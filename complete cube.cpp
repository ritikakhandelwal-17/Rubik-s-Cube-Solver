#include <bits/stdc++.h>
using namespace std;
int top;int bottom;int right1;int left1;
vector < vector <int> > two,three,allstep;
int step=0;
int color_matrix[6][9];


int get_data[3][3][6]={{
{0,4,1,1,2,0},
{5,3,2,0,3,5},
{2,3,5,5,2,4}},{
{2,1,5,4,2,4},
{0,1,2,3,4,5},
{1,2,4,3,5,0}},{
{1,3,5,3,0,3},
{3,1,0,1,4,0},
{2,1,4,4,0,5}}
};

void colorinput(){
	for(int i=0;i<6;i++)
	{ 
	cout<<"input color"<<" "<<i<<endl;
		for(int j=0;j<3;j++)
		{
			for (int k=0;k<3;k++)
			cin>>get_data[j][k][i];
		}
	}
	
}
int color[6][9];
void face_color(){
	for(int i=0;i<6;i++)
	{
		color[i][0]=get_data[1][1][i];
		color[i][1]=get_data[0][1][i];
		color[i][2]=get_data[1][2][i];
		color[i][3]=get_data[2][1][i];
		color[i][4]=get_data[1][0][i];
		color[i][5]=get_data[0][2][i];
		color[i][6]=get_data[2][2][i];
		color[i][7]=get_data[2][0][i];
		color[i][8]=get_data[0][0][i];
		
		
	}
	
}

struct sb{
	int c[3];int v[3][3]={{0,0,0},{0,0,0},{0,0,0}};
};


int assign(int axis[])
{
	if (axis[0] == 1)                       //red
	{
		return 1;
	}

	else if (axis[0]==-1)                 //orange
	{
		return 4;
	}

	else if (axis[1]==1)                 //green
	{
		return 2;
	}
	
	else if (axis[1]==-1)                 //blue
	{
		return 3;
	}
	else if (axis[2]==1)                 //yellow
	{
		return 5;
	}
	else                 //white
	{
		return 0;
	}
}


void dor(int c){
	if (c==1)                       //red
	{
		right1=2;left1=3;top=5;bottom=0;
		
	}
	else if (c==4)                 //orange
	{
		right1=3;left1=2;top=5;bottom=0;
	}
	else if (c==2)                 //green
	{
		right1=4;left1=1;top=5;bottom=0;
	}
	else if (c==3)                 //blue
	{
		right1=1;left1=4;top=5;bottom=0;
	}
	else if (c==5)                 //yellow
	{
		right1=2;left1=3;top=4;bottom=1;
	}
	else if (c==0)                 //white
	{
		right1=2;left1=3;top=1;bottom=4;
	}
}

void for_x(int x,int curr,sb block[3][3][3])
{
	
	dor(curr);
	for (int y=-1;y<=1;y++)
	{
		for(int z=-1;z<=1;z++)
		{
			//cout<<x<<" "<<y<<" "<<z<<endl;

			block[x+1][y+1][z+1].v[0][0] = x;
			
			if(y==0&&z==0)
			{
				block[x+1][y+1][z+1].c[0]=curr;
								
				
			}
			else if(y==0)
			{
				vector <int> a(3);a[0]=x;a[1]=y;a[2]=z;
				two.push_back(a);
				int fa[3]={0,y,z};
				int cc=assign(fa);
				block[x+1][y+1][z+1].v[1][2]=z;
				
					
				if(cc==top)
				{
				int jj=3;
				if(x==-1)
				jj=1;
					block[x+1][y+1][z+1].c[0]=color[curr][1];
					block[x+1][y+1][z+1].c[1]=color[cc][jj];

				
				}
				else if (cc==bottom)
				{
				int jj=1;
				if(x==-1)
				jj=3;
					block[x+1][y+1][z+1].c[0]=color[curr][3];
					block[x+1][y+1][z+1].c[1]=color[cc][jj];
				}
			}
			else if (z==0)
			{
				vector <int> a(3);a[0]=x;a[1]=y;a[2]=z;
				two.push_back(a);
				int fa[3]={0,y,z};
				int cc=assign(fa);
				block[x+1][y+1][z+1].v[1][1]=y;
				
				if(cc==right1)
				{
					block[x+1][y+1][z+1].c[0]=color[curr][2];
					block[x+1][y+1][z+1].c[1]=color[cc][4];
				}
				else 
				{
					block[x+1][y+1][z+1].c[0]=color[curr][4];
					block[x+1][y+1][z+1].c[1]=color[cc][2];
				}
			}
			else
			{
				vector <int> a(3);a[0]=x;a[1]=y;a[2]=z;
				three.push_back(a);
				int fa[3]={0,y,0};
				int cc1=assign(fa);
				int fa1[3]={0,0,z};
				int cc2=assign(fa1);
				block[x+1][y+1][z+1].v[1][1]=y;
				block[x+1][y+1][z+1].v[2][2]=z;
				if(cc1==right1)
				{
					if (cc2==top)
				{
				int jj=6;
				if (x==-1)
				jj=8;
					
					int arr[3]={color[curr][5],color[cc1][8],color[cc2][jj]};
					
					for(int i=0;i<3;i++)
					{	
						block[x+1][y+1][z+1].c[i]=arr[i];}
						
				}
					else
					{
						int jj=5;
				if (x==-1)
				jj=7;
						int s1=color[curr][6];int s2=color[cc1][7];int s3=color[cc2][jj];
						block[x+1][y+1][z+1].c[0]=s1;
						block[x+1][y+1][z+1].c[1]=s2;
						block[x+1][y+1][z+1].c[2]=s3;
					
					}
					
				}
				else
				{
					if (cc2==top)
					{
					int jj=7;
						if(x==-1)
						jj=5;
						int arr[3]={color[curr][8],color[cc1][5],color[cc2][jj]};
						
					for(int i=0;i<3;i++)
					{	
						block[x+1][y+1][z+1].c[i]=arr[i];}
					}
					
					else
					{//cout<<"b"<<endl;
					//cout<<"curr "<<curr<<" cc1 "<<cc1<<" cc2 "<<cc2;
					int jj=8;
				if (x==-1)
				jj=6;
					int q=color[curr][7];int w=color[cc1][6];int e=color[cc2][jj];
					//cout<<"int";
					
						//cout<<"e"<<endl;
					
					block[x+1][y+1][z+1].c[0]=q;
					block[x+1][y+1][z+1].c[1]=w;
					block[x+1][y+1][z+1].c[2]=e;
				}
			}
		}
	}	
}
}

void for_y(int y,int curr,sb block[3][3][3])
{
	block[0+1][y+1][0+1].v[0][1]=y;
	block[0+1][y+1][0+1].c[0]=curr;
	
	

}


void for_z(int z,int curr,sb block[3][3][3])
{
	//cout<<"for_z"<<endl;
	dor(curr);
	int x=0;
	
		for(int y=-1;y<=1;y++)
		{
			block[x+1][y+1][z+1].v[0][2]=z;
			if(x==0&&y==0)
			{
				block[x+1][y+1][z+1].c[0]=curr;
				
			}
		
			else if (x==0)
			{
				vector <int> a(3);a[0]=x;a [1]=y;a[2]=z;
				two.push_back(a);
				int fa[3]={x,y,0};
				int cc=assign(fa);
				block[x+1][y+1][z+1].v[1][1]=y;
				int aa=1;
		
				if(z==-1)
				{aa=3;
				}
				if(cc==right1)
				{
					int arr[3]={color[curr][2],color[cc][aa],-1};
					for(int i=0;i<3;i++)
					block[x+1][y+1][z+1].c[i]=arr[i];
				}
				else 
				{
					int arr[3]={color[curr][4],color[cc][aa],-1};
					for(int i=0;i<3;i++)
					block[x+1][y+1][z+1].c[i]=arr[i];
				
				}
				
			}
			
		}
}


void block_matrix(sb block[3][3][3])
{
	cout<<"block_matrix"<<endl;
	//origin shift to (-1,-1-,1)
	for_x(1,1,block);//red face
	for_x(-1,4,block);
	for_y(1,2,block);
	for_y(-1,3,block);
	for_z(1,5,block);
	for_z(-1,0,block);
}


struct f{
	int v1[3]={0,0,0},v2[3]={0,0,0};
};f face_matrix[6][9];

int* ret_axis(int c){
	
	int axis[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
	if (c==1)                       //red
	{
		right1=2;left1=3;top=5;bottom=0;
		return axis[0];
	}
	else if (c==4)                 //orange
	{
		right1=3;left1=2;top=5;bottom=0;
		return axis[1];
	}
	else if (c==2)                 //green
	{
		right1=4;left1=1;top=5;bottom=0;
		return axis[2];
	}
	else if (c==3)                 //blue
	{
		right1=1;left1=4;top=5;bottom=0;
		return axis[3];
	}
	else if (c==5)                 //yellow
	{
		right1=2;left1=3;top=4;bottom=1;
		return axis[4];
	}
	else if (c==0)                 //white
	{
		right1=2;left1=3;top=1;bottom=4;
		return axis[5];
	}
	
}
void centre(){
	for(int i=0;i<=5;i++)
	{
		int *a1=ret_axis(i);
		for(int ii=0;ii<3;ii++)
	face_matrix[i][0].v1[ii]=face_matrix[i][0].v2[ii]=a1[ii];
	}
}
vector<int> find_2(int c1[3],sb block[3][3][3]) {

	sort(c1,c1+3);
	vector <vector <int> > :: iterator itr=two.begin();
	while (itr<two.end()){
		vector <int> b(*itr);int p[3];
		for(int i=0;i<3;i++)
			p[i]=block[b[0]+1][b[1]+1][b[2]+1].c[i];
		sort(p,p+3);
		if(p[1]==c1[1] && p[2]==c1[2])
		{
			two.erase(itr);
			return b;
		}
		itr++;
	}

}

vector<int> find_3(int c1[3],sb block[3][3][3]){
	sort(c1,c1+3);
	vector <vector <int> > :: iterator itr=three.begin();
	while (true){
		vector <int> b(*itr);int p[3];
		for(int i=0;i<3;i++)
		 p[i]=block[b[0]+1][b[1]+1][b[2]+1].c[i];
		sort(p,p+3);
		if(p[0]==c1[0]&&p[1]==c1[1]&&p[2]==c1[2])
		{
		  three.erase(itr);
			return b;
		}
		itr++;
	}
}


void whitenyellow(int c,sb block[3][3][3])
{
	int *a1=ret_axis(c);
	vector <int> x;int c2,j,c3,k;
	if (c==5)
	j=1;
	else
	j=3;
	for(int i=1;i<=4;i++)
	{		int a2[3],c2;
		if(i==1)
		{
		c2=top;
		//j=3;
		
		int s[3]={c,c2,-1};
		x=find_2(s,block);
		}
		else if (i==2)
		{
	    c2=right1;
	    //j=4;
		int s[3]={c,c2,-1};
		x=find_2(s,block);
		}
		else if (i==3)
		{
		c2=bottom;
		//j=1;
		int s[3]={c,c2,-1};
		x=find_2(s,block);
		}
		else
		{
		 c2=left1;
		 //j=2;
		int s[3]={c,c2,-1};
		x=find_2(s, block);
		}
		for(int ii=0;ii<3;ii++)
		face_matrix[c][i].v1[ii]=face_matrix[c2][j].v1[ii]=x[ii];
		if(block[x[0]+1][x[1]+1][x[2]+1].c[0]==c)
		{
			for(int ii=0;ii<3;ii++)
		{
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];
    	}
		}
		else
		{
			for(int ii=0;ii<3;ii++){
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];}
		}
	}
	for(int i=5;i<9;i++)
	{//cout<<i<<endl; 
	
		if(i==5)
		{
			c2=right1;c3=top;
			if(c==5)
			{
			j=5;k=8;}
			else
		{
				j=7;k=6;}
			int s[3]={c,c2,c3};
			x=find_3(s,block);
		}
		else if(i==6)
		{
			c2=right1;c3=bottom;
			if(c==5)
			{j=8;k=5;
			}
			else
			{j=6;k=7;
			}
			int s[3]={c,c2,c3};
			x=find_3(s,block);
		}
		else if(i==7)
		{
			c2=left1;c3=bottom;
			if(c==5)
			{j=5;k=8;
			}
			else
			{j=7;k=6;
			}
			int s[3]={c,c2,c3};
			cout<<c<<" "<<c2<<" "<<c3<<endl;
			x=find_3(s,block);
		}
		else if(i==8)
		{
			c2=left1;c3=top;
			if(c==5)
			{j=8;k=5;
			}
			else
			{j=6;k=7;
			}
			int s[3]={c,c2,c3};
			x=find_3(s,block);
		}
		for(int ii=0;ii<3;ii++)
		face_matrix[c][i].v1[ii]=face_matrix[c2][j].v1[ii]=face_matrix[c3][k].v1[ii]=x[ii];
		if(block[x[0]+1][x[1]+1][x[2]+1].c[0]==c &&block[x[0]+1][x[1]+1][x[2]+1].c[1]==c2 )
		{
			for(int ii=0;ii<3;ii++)
		{
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];
			face_matrix[c3][k].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[2][ii];
		}
			
		}
		else if(block[x[0]+1][x[1]+1][x[2]+1].c[0]==c &&block[x[0]+1][x[1]+1][x[2]+1].c[1]==c3 )
		{
			for(int ii=0;ii<3;ii++)
			{
			
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[2][ii];
			face_matrix[c3][k].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];
			}
		}
		else if(block[x[0]+1][x[1]+1][x[2]+1].c[0]==c2 &&block[x[0]+1][x[1]+1][x[2]+1].c[1]==c)
		{
				for(int ii=0;ii<3;ii++)
		{
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];
			face_matrix[c3][k].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[2][ii];}
		}
		else if(block[x[0]+1][x[1]+1][x[2]+1].c[0]==c2 &&block[x[0]+1][x[1]+1][x[2]+1].c[1]==c3 )
		{
				for(int ii=0;ii<3;ii++)
		{
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[2][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];
			face_matrix[c3][k].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];}
		}
		else if(block[x[0]+1][x[1]+1][x[2]+1].c[0]==c3 &&block[x[0]+1][x[1]+1][x[2]+1].c[1]==c2 )
		{
				for(int ii=0;ii<3;ii++)
		{
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[2][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];
			face_matrix[c3][k].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];}
		}
		else if(block[x[0]+1][x[1]+1][x[2]+1].c[0]==c3 &&block[x[0]+1][x[1]+1][x[2]+1].c[1]==c )
		{
			for(int ii=0;ii<3;ii++)
		{
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[2][ii];
			face_matrix[c3][k].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];
		}
		}
		
		
		
		
	}
}


void rednorange(int c,sb block[3][3][3]){
	int *a1=ret_axis(c);
	vector <int> x;int c2,j;
	int i=4;j=2;
	c2=left1;
	int s[3]={c,c2,-1};
	x=find_2(s,block);
	for(int ii=0;ii<3;ii++)
	face_matrix[c][i].v1[ii]=face_matrix[c2][j].v1[ii]=x[ii];
		if(block[x[0]+1][x[1]+1][x[2]+1].c[0]==c)
		{	for(int ii=0;ii<3;ii++)
		{
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];}
		}
		else
		{
				for(int ii=0;ii<3;ii++)
		{
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];}
		}
		i=2;j=4;c2=right1;
		int l[3]={c,c2,-1};
		x=find_2(l,block);
		for(int ii=0;ii<3;ii++)
		face_matrix[c][i].v1[ii]=face_matrix[c2][j].v1[ii]=x[ii];
		if(block[x[0]+1][x[1]+1][x[2]+1].c[0]==c)
		{	for(int ii=0;ii<3;ii++)
		{
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];}
		}
		else
		{
				for(int ii=0;ii<3;ii++)
		{
			face_matrix[c][i].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[1][ii];
			face_matrix[c2][j].v2[ii]=block[x[0]+1][x[1]+1][x[2]+1].v[0][ii];}
		}
			
}
void face(sb block[3][3][3]){
	//cout<<"centre"<<" ";
	centre();
//	cout<<"rg"<<endl;
	rednorange(1,block);
//	cout<<"rg"<<endl;

	rednorange(4,block);
//	cout<<"wy"<<" ";
	whitenyellow(5,block);
//	cout<<"wy"<<" ";
	whitenyellow(0,block);
	
}

void print_face_matrix(){
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<9;j++)
		{cout<<"face["<<i<<"]["<<j<<"] "<<" v1 =";
		cout<<face_matrix[i][j].v1[0]<<","<<face_matrix[i][j].v1[1]<<","<<face_matrix[i][j].v1[2]<<endl<<" v2 =";
		cout<<face_matrix[i][j].v2[0]<<","<<face_matrix[i][j].v2[1]<<","<<face_matrix[i][j].v2[2]<<endl;
		}
	}
}

void color_mat(){
	
//	int vec1[3],vec2[3];
	for(int i=0;i<6;i++){
		for(int j=0;j<9;j++){
			int vec1[3]={face_matrix[i][j].v1[0],face_matrix[i][j].v1[1],face_matrix[i][j].v1[2]};
			int vec2[3]={face_matrix[i][j].v2[0],face_matrix[i][j].v2[1],face_matrix[i][j].v2[2]};
			int color=assign(vec2);
			
			dor(color);
			int x1=vec1[0];
			int y1=vec1[1];
			int z1=vec1[2];
			int axis1[3]={x1,0,0};
			int axis2[3]={0,y1,0};
			int axis3[3]={0,0,z1};
			int color1=assign(axis1);
			int color2=assign(axis2);
			int color3=assign(axis3);
			if(x1!=0){
				if(y1!=0){
					if(z1!=0){
						
						if(right1==color1 || right1==color2 || right1==color3){
							if(top==color1 || top==color2 || top==color3){
								color_matrix[color][5]=i;
							}
							else{
								color_matrix[color][6]=i;
							}
						}
						else{
							if(top==color1 || top==color2 || top==color3){
								color_matrix[color][8]=i;
							}
							else{
								color_matrix[color][7]=i;
							}
						}
					}
					else{
						if(right1==color1 || right1==color2 || right1==color3){
							color_matrix[color][2]=i;
						}
						else{
							color_matrix[color][4]=i;
						}
					}
				}
				else{
					if(z1!=0){
						if(top==color1 || top==color2 || top==color3){
							color_matrix[color][1]=i;
						}
						else{
							color_matrix[color][3]=i;
						}
					}
					else{
						color_matrix[color][0]=i;
					}
				}
			}
			else{
				if(y1!=0){
					if(z1!=0){
						if(color==2 || color==3){
							if(top==color1 || top==color2 || top==color3){
							color_matrix[color][1]=i;
							}	
							else{
							color_matrix[color][3]=i;
							}
						}
						else{
							if(right1==color1 || right1==color2 || right1==color3){
							color_matrix[color][2]=i;
							}
							else{
							color_matrix[color][4]=i;
							}
						}
					}
					else{
						color_matrix[color][0]=i;
					}
				}
				else{
					color_matrix[color][0]=i;
				}
			}
			
		}
	}
}

void printallfaces(){
	
	color_mat();
	for(int c=0;c<6;c++){
		cout<< color_matrix[c][8] <<" "<< color_matrix[c][1] << " "<< color_matrix[c][5] << endl;
		cout<< color_matrix[c][4] <<" "<< color_matrix[c][0] << " "<< color_matrix[c][2] << endl;
		cout<< color_matrix[c][7] <<" "<< color_matrix[c][3] << " "<< color_matrix[c][6] << endl;
		cout << "      " <<endl;
		
	}
	cout << " * * *" <<endl;
}


void clockwise(int f){
	
	step++;
//cout<<"clock "<<f<<endl;
	int *v11,*v22;
	int *t=ret_axis(f);
	int v3[3]={t[0],t[1],t[2]};
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<9;j++)
		{
			v11=face_matrix[i][j].v1;
			v22=face_matrix[i][j].v2;
			int v1[3]={v11[0],v11[1],v11[2]};
			int v2[3]={v22[0],v22[1],v22[2]};
			
			if((v1[0]*v3[0] + v1[1]*v3[1] + v1[2]*v3[2])>0)
			{				int v1n[3];
				v1n[0]=(v1[1]*v3[2])-(v1[2]*v3[1]);
				v1n[1]=v3[0]*v1[2]-v3[2]*v1[0];
				v1n[2]=v1[0]*v3[1]-v1[1]*v3[0];
				
				int ans[3];
				ans[0]=(v2[1]*v3[2])-(v2[2]*v3[1]);
				ans[1]=v3[0]*v2[2]-v3[2]*v2[0];
				ans[2]=v2[0]*v3[1]-v2[1]*v3[0];
				if (ans[0]==0&&ans[1]==0&&ans[2]==0)
				{
				ans[0]=v3[0];
				ans[1]=v3[1];ans[2]=v3[2];	}
				for(int k=0;k<3;k++)
				{
				v1n[k]+=v3[k];
				}
				for(int k=0;k<3;k++){
				
				face_matrix[i][j].v1[k]=v1n[k];
				face_matrix[i][j].v2[k]=ans[k];
				}
				}
		}
	}
	
	
}

void anticlockwise(int f){
	//track.push_back(f+6);
	step++;
//	cout<<"anticlock "<<f<<endl;
	int *v33=ret_axis(f);int v3[3]={v33[0],v33[1],v33[2]};
	int v31[3];v31[0]=-v3[0];v31[1]=-v3[1];v31[2]=-v3[2];
	int *v1,*v2;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<9;j++)
		{
			v1=face_matrix[i][j].v1;
			v2=face_matrix[i][j].v2;
			
			if((v1[0]*v3[0] + v1[1]*v3[1] + v1[2]*v3[2])>0)
			{
				int v1n[3];
				v1n[0]=(v1[1]*v31[2])-(v1[2]*v31[1]);
				v1n[1]=v31[0]*v1[2]-v31[2]*v1[0];
				v1n[2]=v1[0]*v31[1]-v1[1]*v31[0];
				
				int ans[3];//=cross(v2,v3);
				
				ans[0]=(v2[1]*v31[2])-(v2[2]*v31[1]);
				ans[1]=v31[0]*v2[2]-v31[2]*v2[0];
				ans[2]=v2[0]*v31[1]-v2[1]*v31[0];
				
				if (ans[0]==0 && ans[1]==0 && ans[2]==0)
				{ans[0]=v3[0];
				ans[1]=v3[1];ans[2]=v3[2];	}
				
				
				
				for(int k=0;k<3;k++)
				{
					v1n[k]+=v3[k];
				}
				for(int k=0;k<3;k++){
				
				face_matrix[i][j].v1[k]=v1n[k];
				face_matrix[i][j].v2[k]=ans[k];}
			}
		}
	}
	
	
}

void reverse(vector <int> track){
//	cout<<"reverse"<<endl;
	vector<int> back;
	int n=track.size();
//	cout<<"size  "<<n<<endl;
	for(int i=n-1;i>=0;i--)
	{
		
		if (track[i]>5)
		clockwise(track[i]-6);
		else
		anticlockwise(track[i]);
	}
}

void finalstep1(vector <int> &lo , vector <int> &total_track )
{//cout<<"here"<<endl;
printallfaces();
	vector<int> done;done.push_back(-1);
	vector<int> track;step=0;
	for(int u=1;u<=4;u++)
	{
		
	
	int i=lo[u];

	int wco[5]={-1,1,2,4,3};

		int p=wco[i];//second color
		done.push_back(p);
		int j=3;
		int *aa=ret_axis(p);//axis of second color of block
		int a[3]={aa[0],aa[1],aa[2]};
		int *v=face_matrix[p][j].v2;//area vector of second color of block
		int *t=face_matrix[0][i].v2;
		int fc=assign(t);//face color with 1
		int sc=assign(v);//face color with 2
		dor(sc);
		
		if (u==1 && face_matrix[0][i].v2[2]==-1 )//white face
		{
//		cout<<"white face for red"<<endl;//a=ret_axis(p);
		if(sc==p);
		else if(right1==p)
		{clockwise(0);track.push_back(0);
		}
		else if(left1==p)
		{anticlockwise(0);track.push_back(6);
		}
		else
		{clockwise(0);clockwise(0);
		track.push_back(0);track.push_back(0);
		}
		}
		
		else if (face_matrix[0][i].v2[2]==-1)//white face
		{
//		cout<<"white face "<<endl;

			if(a[0]!=v[0] || a[1]!=v[1] || a[2]!=v[2])
			{
				
					for(int jj=1;jj<u;jj++)
					{clockwise(done[jj]);track.push_back(done[jj]);
					}
					dor(sc);
					
				if(p==left1)
				{anticlockwise(0);track.push_back(6);

				}		
				else if(p==right1)
				{clockwise(0);track.push_back(0);
				}
				else
			   {
			   clockwise(0);clockwise(0);
			   track.push_back(0);track.push_back(0);
			   }
			for(int jj=u-1;jj>0;jj--)
			{anticlockwise(done[jj]);track.push_back(done[jj]+6);
			}
			}
			
		}
		else if (face_matrix[0][i].v1[2]==-1) //white layer
		{
//			cout<<"white layer "<<fc<<endl;
				if(a[0]==t[0] && a[1]==t[1] && a[2]==t[2])
				{
				anticlockwise(fc);track.push_back(fc+6);
				
				int *temp=face_matrix[p][j].v2;
				int n=assign(temp);
				dor(n);
				if(right1==fc)
				{
					anticlockwise(0);track.push_back(6);
					clockwise(n);track.push_back(n);
					clockwise(0);track.push_back(0);
				}
				else
				{
					clockwise(0);track.push_back(0);
					anticlockwise(n);track.push_back(n+6);
					anticlockwise(0);track.push_back(6);
				}
				}
				
				else{
				int zz=0;
					dor(fc);
					if(right1==p)
					{anticlockwise(fc);track.push_back(fc+6);
					anticlockwise(p);track.push_back(p+6);
					}
					else if(left1==p)
					{clockwise(fc);track.push_back(fc);
					clockwise(p);track.push_back(p);
					}
					else if (u==1)
					{
						
						
					 	clockwise(fc);track.push_back(fc);
						int *temp=face_matrix[p][j].v2;
				        int n=assign(temp);
				        clockwise(n);track.push_back(n);
				         anticlockwise(0);track.push_back(6);
							
						
					
					}
					else
					{
						if(((u==2) && right1!=done[1]) || (i==3 && right1!=done[1] && right1!=done[2]))
					{anticlockwise(fc);track.push_back(fc+6);
					}
					else if (((u==2) && left1!=done[1]) || (i==3 && left1!=done[1] && left1!=done[2]))
					{clockwise(fc);track.push_back(fc);
					}
					else
					{
						zz=1;
						clockwise(fc);track.push_back(fc);
					}
					int *temp=face_matrix[p][j].v2;
				    int n=assign(temp);
				    dor(n);
				    if(right1==fc)
				    {anticlockwise(n);track.push_back(n+6);
				    if (right1==p)
				    {anticlockwise(5);track.push_back(11);
					}
				    else if (left1==p)
				    {clockwise(5);track.push_back(5);
					}
				    else
				    {clockwise(5);clockwise(5);track.push_back(5);track.push_back(5);
					}
				    if(zz)
				    {clockwise(n);track.push_back(n);
					}
					}
					
				    else 
				    {clockwise(n);track.push_back(n);
				    if (right1==p)
				    {anticlockwise(5);track.push_back(11);
					}
				    else if (left1==p)
				    {clockwise(5);track.push_back(5);
					}
				    else
				    {clockwise(5);clockwise(5);track.push_back(5);track.push_back(5);
					}
				    if(zz)
				    {anticlockwise(n);track.push_back(n+6);
					}
					}
					u--;
					}
				    
					}
					
					
				}
		
		else if (face_matrix[0][i].v2[2]==1)//yellow face
		{
//		cout<<"yellow face "<<endl;
			if(a[0]!=v[0] || a[1]!=v[1] || a[2]!=v[2])
			{//cout<<" right1 "<<right1<<endl;
			if(right1==p)
			{anticlockwise(5);track.push_back(11);
			}
			else if (left1==p)
			{clockwise(5);track.push_back(5);
			}
			else
			{clockwise(5);clockwise(5);track.push_back(5);track.push_back(5);
			}
			}
			clockwise(p);clockwise(p);track.push_back(p);track.push_back(p);
		}
		else if (face_matrix[0][i].v1[2]==1)//yellow layer
		{
//			cout<<"yellow layer"<<endl;
			if(a[0]!=t[0] || a[1]!=t[1] || a[2]!=t[2])
			{dor(fc);
			if(right1==p)
			{clockwise(fc);track.push_back(fc);
			anticlockwise(p);track.push_back(p+6);
			if((u==2&&done[1]==fc)||(u==3&&(done[1]==fc||done[2]==fc))||u==4)
			{anticlockwise(fc);track.push_back(fc+6);
			}
			}
			else if (left1==p)
			{anticlockwise(fc);track.push_back(fc+6);
			clockwise(p);track.push_back(p);
			if((u==2&&done[1]==fc)||(u==3&&(done[1]==fc||done[2]==fc))||u==4)
			{clockwise(fc);track.push_back(fc);
			}
			}
			else
			{
			dor(fc);
			clockwise(5);track.push_back(5);
			int *temp=face_matrix[0][i].v2;
			int tt=assign(temp);
			dor(tt);
			
			anticlockwise(tt);track.push_back(tt+6);
			clockwise(p);track.push_back(p);
			if((u==2&&done[1]==tt)||(u==3&&(done[1]==tt||done[2]==tt))||u==4)
			{
			clockwise(tt);track.push_back(tt);	
			}
			}
			}
			else
			{clockwise(p);track.push_back(p);u--;
			}
			
		}
		else
		{
//			cout<<"else"<<endl;
			
			if(a[0]==v[0] && a[1]==v[1] && a[2]==v[2])
			{//cout<<"a"<<endl;
				if(right1==fc)
				{clockwise(p);track.push_back(p);
				}
				else
				{anticlockwise(p);track.push_back(p+6);
				}
				//printallfaces();
			}
			else if(a[0]==t[0] && a[1]==t[1] && a[2]==t[2])
			{
//			cout<<"b"<<endl;
				if(right1==p)
				{//cout<<"aa"<<endl;
					anticlockwise(0);track.push_back(6);
					clockwise(sc);track.push_back(sc);
					clockwise(0);track.push_back(0);
				
				}
				else
				{
//				cout<<"as"<<endl;
					clockwise(0);track.push_back(0);
					anticlockwise(sc);track.push_back(sc+6);
					anticlockwise(0);track.push_back(6);
					
				}
			}
			else
			{
//			cout<<"c"<<endl;
				if(u==1)
				{
					if(left1==fc)
					{anticlockwise(sc);track.push_back(sc+6);
					}
					else 
					{clockwise(sc);track.push_back(sc);
					}
					if(right1==p)
					{clockwise(0);track.push_back(0);
					}
					else if(left1==p)
					{anticlockwise(0);track.push_back(6);
					}
					else
					{anticlockwise(0);anticlockwise(0);track.push_back(6);track.push_back(6);
					}
					
				}
				else if(left1==fc)
				{
//				cout<<"d"<<endl;
					clockwise(sc);track.push_back(sc);
					if(right1==p)
					{anticlockwise(5);track.push_back(11);
					}
					else if(left1==p)
					{clockwise(5);track.push_back(5);
					}
					else
				{	anticlockwise(5);	anticlockwise(5);
				track.push_back(11);track.push_back(11);
				}
					
					
					if((u==2&&sc==done[1])||(u==3&&(sc==done[1]||sc==done[2]))||u==4 )
					{anticlockwise(sc);track.push_back(sc+6);
					}
				u--;	
				}
				else
				{
//				cout<<"e"<<sc<<endl;
				anticlockwise(sc);track.push_back(sc+6);
				
				
					
					if(right1==p)
					{anticlockwise(5);track.push_back(11);
					}
					else if(left1==p)
					{clockwise(5);track.push_back(5);
					}
					else
				{	anticlockwise(5);	anticlockwise(5);track.push_back(11);track.push_back(11);
				}
					if((u==2&&sc==done[1])||(u==3&&(sc==done[1]||sc==done[2]))||u==4 )
					{//cout<<"yes";
					clockwise(sc);track.push_back(sc);
					}
					
				u--;	
				}
				
			}
			
		
		}
		
	//cout<<"i "<<i<<endl;	
	//printallfaces();
	}
	
	
	for(int tr=0;tr<track.size();tr++)
	{
			cout<<track[tr]<<" ";
			total_track.push_back(track[tr]);

	}
	cout<<endl<<"no of steps"<<step<<endl;
	
}


void step1(vector <int> &total_track){//cout<<"white cross"<<endl;
vector <int> noofstep;int min=50,mi;
int s[24][5]={{-1,1,2,3,4},{-1,1,2,4,3},{-1,1,3,2,4},{-1,1,3,4,2},{-1,1,4,3,2},{-1,1,4,2,3},
			  {-1,2,3,4,1},{-1,2,3,1,4},{-1,2,4,1,3},{-1,2,4,3,1},{-1,2,3,1,4},{-1,2,3,4,1},
			  {-1,3,4,1,2},{-1,3,4,2,1},{-1,3,1,2,4},{-1,3,1,4,2},{-1,3,2,1,4},{-1,3,2,4,1},
			  {-1,4,1,2,3},{-1,4,1,3,2},{-1,4,2,1,3},{-1,4,2,3,1},{-1,4,3,1,2},{-1,4,3,2,1},};
for(int ss=0;ss<24;ss++)
{
//cout<<ss<<endl;
	 vector<int> track;
		step=0;
		vector<int> done;done.push_back(-1);
		for(int u=1;u<=4;u++)
	{
		
	int *lp=s[ss]; 
	int lo[5]={lp[0],lp[1],lp[2],lp[3],lp[4]};	
		
	int i=lo[u];
//cout<<"i"<<i<<" ";
	int wco[5]={-1,1,2,4,3};
	
		int p=wco[i];//second color
		done.push_back(p);
		int j=3;
		int *aa=ret_axis(p);//axis of second color of block
		int a[3]={aa[0],aa[1],aa[2]};
		int *v=face_matrix[p][j].v2;//area vector of second color of block
		int *t=face_matrix[0][i].v2;
		int fc=assign(t);//face color with 1
		int sc=assign(v);//face color with 2
		dor(sc);
		
		if (u==1 && face_matrix[0][i].v2[2]==-1 )//white face
		{
//		cout<<"white face for red"<<endl;//a=ret_axis(p);
		if(sc==p);
		else if(right1==p)
		{clockwise(0);track.push_back(0);
		}
		else if(left1==p)
		{anticlockwise(0);track.push_back(6);
		}
		else
		{clockwise(0);clockwise(0);
		track.push_back(0);track.push_back(0);
		}
		}
		
		else if (face_matrix[0][i].v2[2]==-1)//white face
		{
//		cout<<"white face "<<endl;

			if(a[0]!=v[0] || a[1]!=v[1] || a[2]!=v[2])
			{
//				cout<<"in if"<<endl;

					for(int jj=1;jj<u;jj++)
					{clockwise(done[jj]);track.push_back(done[jj]);
					}
					
					dor(sc);
					
				if(p==left1)
				{anticlockwise(0);track.push_back(6);

				}		
				else if(p==right1)
				{clockwise(0);track.push_back(0);
				}
				else
			   {
			   clockwise(0);clockwise(0);track.push_back(0);track.push_back(0);
			   }
			for(int jj=u-1;jj>0;jj--)
			{anticlockwise(done[jj]);track.push_back(done[jj]+6);
			}
			}
			
		}
		else if (face_matrix[0][i].v1[2]==-1) //white layer
		{
//			cout<<"white layer "<<fc<<endl;
				if(a[0]==t[0] && a[1]==t[1] && a[2]==t[2])
				{
				anticlockwise(fc);track.push_back(fc+6);
				
				int *temp=face_matrix[p][j].v2;
				int n=assign(temp);
				dor(n);
				if(right1==fc)
				{
					anticlockwise(0);track.push_back(6);
					clockwise(n);track.push_back(n);
					clockwise(0);track.push_back(0);
				}
				else
				{
					clockwise(0);track.push_back(0);
					anticlockwise(n);track.push_back(n+6);
					anticlockwise(0);track.push_back(6);
				}
				}
				
				else{
				int zz=0;
					dor(fc);
					if(right1==p)
					{anticlockwise(fc);track.push_back(fc+6);
					anticlockwise(p);track.push_back(p+6);
					}
					else if(left1==p)
					{clockwise(fc);track.push_back(fc);
					clockwise(p);track.push_back(p);
					}
					else if (u==1)
					{
						
						
					 	clockwise(fc);track.push_back(fc);
						int *temp=face_matrix[p][j].v2;
				        int n=assign(temp);
				        clockwise(n);track.push_back(n);
				         anticlockwise(0);track.push_back(6);
							
						
					
					}
					else
					{
						if(((u==2) && right1!=done[1]) || (i==3 && right1!=done[1] && right1!=done[2]))
					{anticlockwise(fc);track.push_back(fc+6);
					}
					else if (((u==2) && left1!=done[1]) || (i==3 && left1!=done[1] && left1!=done[2]))
					{clockwise(fc);track.push_back(fc);
					}
					else
					{
						zz=1;
						clockwise(fc);track.push_back(fc);
					}
					int *temp=face_matrix[p][j].v2;
				    int n=assign(temp);
				    dor(n);
				    if(right1==fc)
				    {anticlockwise(n);track.push_back(n+6);
				    if (right1==p)
				    {anticlockwise(5);track.push_back(11);
					}
				    else if (left1==p)
				    {clockwise(5);track.push_back(5);
					}
				    else
				    {clockwise(5);clockwise(5);track.push_back(5);track.push_back(5);
					}
				    if(zz)
				    {clockwise(n);track.push_back(n);
					}
					}
					
				    else 
				    {clockwise(n);track.push_back(n);
				    if (right1==p)
				    {anticlockwise(5);track.push_back(11);
					}
				    else if (left1==p)
				    {clockwise(5);track.push_back(5);
					}
				    else
				    {clockwise(5);clockwise(5);track.push_back(5);track.push_back(5);
					}
				    if(zz)
				    {anticlockwise(n);track.push_back(n+6);
					}
					}
					u--;
					}
				    
					}
					
					
				}
		
		else if (face_matrix[0][i].v2[2]==1)//yellow face
		{
//		cout<<"yellow face "<<endl;
			if(a[0]!=v[0] || a[1]!=v[1] || a[2]!=v[2])
			{//cout<<" right1 "<<right1<<endl;
			if(right1==p)
			{anticlockwise(5);track.push_back(11);
			}
			else if (left1==p)
			{clockwise(5);track.push_back(5);
			}
			else
			{clockwise(5);clockwise(5);track.push_back(5);track.push_back(5);
			}
			}
			clockwise(p);clockwise(p);track.push_back(p);track.push_back(p);
		}
		else if (face_matrix[0][i].v1[2]==1)//yellow layer
		{
//			cout<<"yellow layer"<<endl;
			if(a[0]!=t[0] || a[1]!=t[1] || a[2]!=t[2])
			{dor(fc);
			if(right1==p)
			{clockwise(fc);track.push_back(fc);
			anticlockwise(p);track.push_back(p+6);
			if((u==2&&done[1]==fc)||(u==3&&(done[1]==fc||done[2]==fc))||u==4)
			{anticlockwise(fc);track.push_back(fc+6);
			}
			}
			else if (left1==p)
			{anticlockwise(fc);track.push_back(fc+6);
			clockwise(p);track.push_back(p);
			if((u==2&&done[1]==fc)||(u==3&&(done[1]==fc||done[2]==fc))||u==4)
			{clockwise(fc);track.push_back(fc);
			}
			}
			else
			{
			//cout<<"here"<<p<<" "<<i<<" "<<fc<<endl;
			dor(fc);
			clockwise(5);track.push_back(5);
			int *temp=face_matrix[0][i].v2;
			int tt=assign(temp);
			dor(tt);
			
			anticlockwise(tt);track.push_back(tt+6);
			clockwise(p);track.push_back(p);
			if((u==2&&done[1]==tt)||(u==3&&(done[1]==tt||done[2]==tt))||u==4)
			{
			clockwise(tt);track.push_back(tt);	
			}
			}
			}
			else
			{clockwise(p);track.push_back(p);u--;
			}
			
		}
		else
		{
//			cout<<"else"<<endl;
		
			if(a[0]==v[0] && a[1]==v[1] && a[2]==v[2])
			{//cout<<"a"<<endl;
				if(right1==fc)
				{clockwise(p);track.push_back(p);
				}
				else
				{anticlockwise(p);track.push_back(p+6);
				}
				//printallfaces();
			}
			else if(a[0]==t[0] && a[1]==t[1] && a[2]==t[2])
			{//cout<<"b"<<endl;
				if(right1==p)
				{//cout<<"aa"<<endl;
					anticlockwise(0);track.push_back(6);
					clockwise(sc);track.push_back(sc);
					clockwise(0);track.push_back(0);
				
				}
				else
				{//cout<<"as"<<endl;
					clockwise(0);track.push_back(0);
					anticlockwise(sc);track.push_back(sc+6);
					anticlockwise(0);track.push_back(6);
					
				}
			}
			else
			{//cout<<"c"<<endl;
				if(u==1)
				{
					if(left1==fc)
					{anticlockwise(sc);track.push_back(sc+6);
					}
					else 
					{clockwise(sc);track.push_back(sc);
					}
					if(right1==p)
					{clockwise(0);track.push_back(0);
					}
					else if(left1==p)
					{anticlockwise(0);track.push_back(6);
					}
					else
					{anticlockwise(0);anticlockwise(0);track.push_back(6);track.push_back(6);
					}
					
				}
				else if(left1==fc)
				{//cout<<"d"<<endl;
					clockwise(sc);track.push_back(sc);
					if(right1==p)
					{anticlockwise(5);track.push_back(11);
					}
					else if(left1==p)
					{clockwise(5);track.push_back(5);
					}
					else
				{	anticlockwise(5);	anticlockwise(5);
				track.push_back(11);track.push_back(11);
				}
					
					
					if((u==2&&sc==done[1])||(u==3&&(sc==done[1]||sc==done[2]))||u==4 )
					{anticlockwise(sc);track.push_back(sc+6);
					}
				u--;	
				}
				else
				{//cout<<"e"<<endl;
				if(right1=fc)
				{anticlockwise(sc);track.push_back(sc+6);
				}
				else
				{clockwise(sc);track.push_back(sc);
				}
					
					if(right1==p)
					{anticlockwise(5);track.push_back(11);
					}
					else if(left1==p)
					{clockwise(5);track.push_back(5);
					}
					else
				{	anticlockwise(5);	anticlockwise(5);track.push_back(11);track.push_back(11);
				}
					if((u==2&&sc==done[1])||(u==3&&(sc==done[1]||sc==done[2]))||u==4 )
					{clockwise(sc);track.push_back(sc);
					}
					
				u--;	
				}
				
			}
			
		
		}
	
		
	}
	if(step<min)
	{min=step;
	mi=ss;
	}
	//printallfaces();
	allstep.push_back(track);
//	cout<<"steps  "<<step<<" track "<<track.size()<<endl;
	noofstep.push_back(step);
//	for(int tr=0;tr<track.size();tr++)
//	cout<<track[tr]<<" ";
//	cout<<endl;
	reverse(track);
//	printallfaces();
//	int z;cin>>z;
	}
//int mi=(min_element(noofstep.begin(),noofstep.end()))-noofstep.begin();
//cout<<"mi"<<mi;
vector <int> final;
final.push_back(s[mi][0]);
final.push_back(s[mi][1]);
final.push_back(s[mi][2]);
final.push_back(s[mi][3]);
final.push_back(s[mi][4]);

//cout<<"final"<<final[1]<<" "<<final[2]<<" "<<final[3]<<" "<<final[4]<<endl;

finalstep1(final,total_track);

}

vector <int> set_data(int i)
{
	vector <int> x;
	if(i==5)
	{x.push_back(1);x.push_back(6);x.push_back(2);x.push_back(7);
	x.push_back(1);x.push_back(2);x.push_back(2);x.push_back(4);
	}
	else if(i==6)
	{x.push_back(2);x.push_back(6);x.push_back(4);x.push_back(7);
	x.push_back(2);x.push_back(2);x.push_back(4);x.push_back(4);
	}
	else if(i==7)
	{
		x.push_back(3);x.push_back(7);x.push_back(4);x.push_back(6);
		x.push_back(3);x.push_back(4);x.push_back(4);x.push_back(2);
	}
	else if (i==8)
	{
		x.push_back(1);x.push_back(7);x.push_back(3);x.push_back(6);
		x.push_back(1);x.push_back(4);x.push_back(3);x.push_back(2);
	}
	return x;
}
int r,l,t,b;
dorx(int c)
{if (c==1)                       //red
	{
		r=2;l=3;t=5;b=0;
		
	}
	else if (c==4)                 //orange
	{
		r=3;l=2;t=5;b=0;
	}
	else if (c==2)                 //green
	{
		r=4;l=1;t=5;b=0;
	}
	else if (c==3)                 //blue
	{
		r=1;l=4;t=5;b=0;
	}
	else if (c==5)                 //yellow
	{
		r=2;l=3;t=4;b=1;
	}
	else if (c==0)                 //white
	{
		r=2;l=3;t=1;b=4;
	}
}
void same_color_on_yellow(int c1,int c2,int c3,int c4,int t1,int t2,int t3,int i,int cx,int tx,vector<int> &track)
{
	//vector <int> track;
	vector <int> x=set_data(i);
	//allign white to face color c2
	
	//cout<<"vvv "<<c4<<" "<<right1<<" "<<left1<<endl;
	
	dorx(c4);
//	cout<<"vvv "<<c4<<" "<<r<<" "<<l<<" "<<c2<<endl;
	
	if (c4==c2);
	else if (r==c2)
	{
		anticlockwise(5);track.push_back(11);
	}
	else if (l==c2)
	{
		
		clockwise(5);track.push_back(5);
	}
	else
	{
	clockwise(5);clockwise(5);	
	track.push_back(5);track.push_back(5);
	}

	//setting middle peice
	c4=c2;
	int *va=face_matrix[c2][cx].v2;
	int *tva=face_matrix[t2][tx].v2;
	c3=assign(va);
	t3=assign(tva);
//	cout<<"c4 "<<c4<<"c3 "<<c3<<endl;
	dorx(c4);
	
	if(r==c3)
	{
		clockwise(c4);track.push_back(c4);
		int np=abs(5-c1);
		dorx(t3);
		if(r==np)
		{
		anticlockwise(5);track.push_back(11);	
		}
		else if(l==np)
		{
		clockwise(5);track.push_back(5);	
		}
		else
		{
		clockwise(5);track.push_back(5);
		clockwise(5);track.push_back(5);
		}
		anticlockwise(c4);track.push_back(c4+6);
		clockwise(5);track.push_back(5);
		clockwise(5);track.push_back(5);
	}
	else
	{
		anticlockwise(c4);track.push_back(c4+6);
		int np=abs(5-c1);
		dorx(t3);
		if(r==np)
		{
		anticlockwise(5);track.push_back(11);	
		}
		else if(l==np)
		{
		clockwise(5);track.push_back(5);	
		}
		else
		{
		clockwise(5);track.push_back(5);
		clockwise(5);track.push_back(5);
		}
		clockwise(c4);track.push_back(c4);
		clockwise(5);track.push_back(5);
		clockwise(5);track.push_back(5);
	}
	dorx(c1);
	if(r==c2)
	{
		clockwise(c2);track.push_back(c2);
		anticlockwise(5);track.push_back(11);
		anticlockwise(c2);track.push_back(c2+6);
	}
	else
	{
		anticlockwise(c2);track.push_back(c2+6);
		clockwise(5);track.push_back(5);
		clockwise(c2);track.push_back(c2);
		
	}
	
}
void different_color_on_yellow(int c1,int c2,int c3,int c4,int t1,int t2,int t3,int i,int cx,int tx,vector<int> &track)
{
	//vector <int> track;
	if(t3==c3)
	{//cout<<" t3==c3 "<<endl;
		dorx(t3);
		int np=abs(5-c1);
		if(t3==np);
		else if(r==np)
		{
			anticlockwise(5);track.push_back(11);
		}
		else if(l==np)
		{
			clockwise(5);track.push_back(5);
		}
		else
		{
			clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
		}
		dorx(np);
		if(l==c2)
		{
			clockwise(c2);track.push_back(c2);
			clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
			anticlockwise(c2);track.push_back(c2+6);
		}
		else
		{
			anticlockwise(c2);track.push_back(c2+6);
			clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
			clockwise(c2);track.push_back(c2);
		}
//	cout<<"fmv1 "<<face_matrix[4][4].v1[0]<<" "<<face_matrix[4][4].v1[1]<<" "<<face_matrix[4][4].v1[2]<<endl;
//	cout<<"fmv2 "<<face_matrix[4][4].v2[0]<<" "<<face_matrix[4][4].v2[1]<<" "<<face_matrix[4][4].v2[2]<<endl;		
		
	}
	else if (c4==c2)
		{
		//cout<<" c4==c2 "<<endl;
			dorx(c4);
			if(r==c1)
			{
			anticlockwise(c2);track.push_back(c2+6);
			int np=abs(5-c3);
			dorx(t3);
			if(t3==np);
			else if(l==np)
			{clockwise(5);track.push_back(5);
			}
			else if(r==np)
			{anticlockwise(5);track.push_back(11);
			}
			else
			{clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
			}
			clockwise(c2);track.push_back(c2);	
			}
			else
			{
			clockwise(c2);track.push_back(c2);	
			int np=abs(5-c3);
			dorx(t3);
			if(t3==np);
			else if(l==np)
			{clockwise(5);track.push_back(5);
			}
			else if(r==np)
			{anticlockwise(5);track.push_back(11);
			}
			else
			{clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
			}
			anticlockwise(c2);track.push_back(c2+6);		
			}
			//came on right pos.
			//yellow_face(i);
			
		}
		else if (t3==c2)
		{//cout<<" t3==c2 "<<endl;
			dorx(t3);
			if(r==c1)
			{
			anticlockwise(c2);track.push_back(c2+6);
			int np=abs(5-t3);
			dorx(c3);
			if(c3==np);
			else if(l==np)
			{clockwise(5);track.push_back(5);
			}
			else if(r==np)
			{anticlockwise(5);track.push_back(11);
			}
			else
			{clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
			}
			clockwise(c2);track.push_back(c2);	
			}
			else
			{
			clockwise(c2);track.push_back(c2);	
			int np=abs(5-t3);
			dorx(c3);
			if(c3==np);
			else if(l==np)
			{clockwise(5);track.push_back(5);
			}
			else if(r==np)
			{anticlockwise(5);track.push_back(11);
			}
			else
			{clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
			}
			anticlockwise(c2);track.push_back(c2+6);		
			}
			//came on right pos.
		//	yellow_face(i);
			
		}
		else if(c4==c1)
		{//cout<<" c4==c1 "<<endl;
			dorx(c1);
			if(r==c2)
			{anticlockwise(5);track.push_back(11);
			}
			else
			{clockwise(5);track.push_back(5);
			}
		//	yellow_face(i);
			
		}
		else if(t3==c1)
		{//cout<<" t3==c1 "<<endl;
			dorx(c1);
			if(r==c2)
			{anticlockwise(c1);track.push_back(c1+6);
			dorx(c4);
			if(r==c2)
			{anticlockwise(5);track.push_back(11);
			}
			else
			{clockwise(5);track.push_back(5);
			}
			clockwise(c1);track.push_back(c1);
			}
			
			else
			{clockwise(c1);track.push_back(c1);
			dorx(c4);
			if(r==c2)
			{anticlockwise(5);track.push_back(11);
			}
			else
			{clockwise(5);track.push_back(5);
			}
			anticlockwise(c1);track.push_back(c1+6);
			}
			
		//yellow_face(i);	
		}
		else
		{//cout<<" else "<<endl;
			clockwise(5);track.push_back(5);
		}
	
}

void yellow_face(int i,vector<int> &track)//both peice on yellow layer and white not on top
{
//	cout<<"yellow face"<<endl;	
	//	printallfaces();
	vector <int> x=set_data(i);
//	vector <int> track;
	int c1;//color of peice on yellow face
	int c2;//other color
	int c3;//face color of c2
	int c4;//face color of white
	int* va=face_matrix[x[0]][x[1]].v2;
	int* vb=face_matrix[x[2]][x[3]].v2; 
	int* vc=face_matrix[0][i].v2;
	c4=assign(vc);
	int cx;
	if (va[2]==1)
	{
		c1=x[0];
		c2=x[2];
		c3=assign(vb);
		cx=x[3];
	}
	else
	{
		c1=x[2];
		c2=x[0];
		c3=assign(va);
		cx=x[1];
	}
	int t1;//color of middle peice on yellow face
	int t2;//other color
	int t3;//face color of t2
	int tx;
	int* tva=face_matrix[x[4]][x[5]].v2;
	int* tvb=face_matrix[x[6]][x[7]].v2; 
	if (tva[2]==1)
	{
		t1=x[4];
		t2=x[6];
		t3=assign(tvb);
		tx=x[7];
	}
	else
	{
		t1=x[6];
		t2=x[4];
		t3=assign(tva);
		tx=x[5];
	}
//	cout<<"assignment"<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<" "<<t1<<" "<<t2<<" "<<t3<<endl;
	
	if(t1==c1)//same color on yellow face
	{
//	cout<<"same color on yellow face"<<endl;
		if(c3==t3)//right position of pair
		{
//		cout<<"right position"<<endl;
		dorx(c3);
		//align c2 with c1 face 
		if(c3==c1);
		else if(r==c1)
		{anticlockwise(5);track.push_back(11);
		}
		else if(l==c1)
		{clockwise(5);track.push_back(5);
		}
		else
		{clockwise(5);track.push_back(5);
		clockwise(5);track.push_back(5);	
		}
		dorx(c2);
		if(r==c1)
		{
			anticlockwise(c2);track.push_back(c2+6);
			clockwise(5);track.push_back(5);
			clockwise(c2);track.push_back(c2);
		}
		else
		{
			clockwise(c2);track.push_back(c2);
			anticlockwise(5);track.push_back(11);
			anticlockwise(c2);track.push_back(c2+6);
		}
		}
		else  if (t3==c4)
		{
//		cout<<"with white"<<endl;
		dorx(c4);
		if(c4==c1);
		else if(r==c1)
		{anticlockwise(5);track.push_back(11);
		}
		else if(l==c1)
		{clockwise(5);track.push_back(5);
		}
		else
		{clockwise(5);track.push_back(5);
		clockwise(5);track.push_back(5);	
		}
		dorx(c1);
		if(l==c2)
		{clockwise(c1);track.push_back(c1);
		anticlockwise(5);track.push_back(11);
		anticlockwise(c1);track.push_back(c1+6);
		}
		else
		{anticlockwise(c1);track.push_back(c1+6);
		clockwise(5);track.push_back(5);
		clockwise(c1);track.push_back(c1);
		}
		yellow_face(i,track);
		}
	
		else
		{
			//cout<<"else"<<endl;
			same_color_on_yellow(c1,c2,c3,c4,t1,t2,t3,i,cx,tx,track);
		}
		
	}
	else //different color on yellow face
	{
//		cout<<"different color on yellow face"<<endl;
	//	cout<<c3<<" "<<t3<<endl;
		if(c3+t3==5)//correct position
		{
	//		cout<<"correct position"<<endl;
			//allign white with c1
			dorx(c4);
			if(c4==c1);
			else if (r==c1)
			{anticlockwise(5);track.push_back(11);
			}
			else if (l==c1)
			{clockwise(5);track.push_back(5);
			}
			else
			{clockwise(5);track.push_back(5);
			clockwise(5);track.push_back(5);
			}
			dorx(c1);
			if (l==c2)
			{clockwise(c1);track.push_back(c1);
			clockwise(5);track.push_back(5);
			anticlockwise(c1);track.push_back(c1+6);
			}
			else 
			{anticlockwise(c1);track.push_back(c1+6);	
			anticlockwise(5);track.push_back(11);
			clockwise(c1);track.push_back(c1);
			}
		}
		else if (c4==t3)
		{
			//allign white side to c1 face color
//			cout<<"allign white side to c1 face color"<<endl;
			dorx(c4);
			if(c4==c1);
			else if (l==c1)
			{clockwise(5);track.push_back(5);
			}
			else if (r==c1)
			{anticlockwise(5);track.push_back(11);
			}
			else
			{clockwise(5);track.push_back(5);
			clockwise(5);track.push_back(5);
			}
			dorx(c1);
			if (l==c2)
			{clockwise(c1);track.push_back(c1);
			anticlockwise(5);track.push_back(11);
			anticlockwise(c1);track.push_back(c1+6);
			}
			else 
			{anticlockwise(c1);track.push_back(c1+6);
			clockwise(5);track.push_back(5);
			clockwise(c1);track.push_back(c1);
			}
			//coverted to corrected pos. case
			yellow_face(i,track);
		}
		else
		{
//			cout<<"dif"<<endl;
		//	int z;cin>>z;
			different_color_on_yellow(c1,c2,c3,c4,t1,t2,t3,i,cx,tx,track);
			yellow_face(i,track);
		}
		
	}
//	int l;cin>>l;
	
}

void yellow_face_with_white(int i,vector<int> &track)//both peice on yellow layer and white on top
{
//	cout<<"yellow face with white on top"<<endl;
	vector <int> x=set_data(i);
	//vector <int> track;
	int c1;//color 1(top of 2 peice)
	int c2;//color 2
	int c3;//face color of c1
	int c4;//face color of c2	
	int t1;//color of middle peice on yellow face
	int t2;//other color
	int t3;//face color of t2
	//int tx;
	int* tva=face_matrix[x[4]][x[5]].v2;
	int* tvb=face_matrix[x[6]][x[7]].v2; 
	
	if (tva[2]==1)
	{
		t1=x[4];
		t2=x[6];
		t3=assign(tvb);
		int* va=face_matrix[x[0]][x[1]].v2;
		int* vb=face_matrix[x[2]][x[3]].v2; 
		int* vc=face_matrix[0][i].v2;
		c3=assign(va);
		c4=assign(vb);
		
		//tx=x[7];
	}
	else
	{
		t1=x[6];
		t2=x[4];
		t3=assign(tva);
		int* va=face_matrix[x[0]][x[1]].v2;
		int* vb=face_matrix[x[2]][x[3]].v2; 
		int* vc=face_matrix[0][i].v2;
		c3=assign(vb);
		c4=assign(va);
		//tx=x[5];
	}
	c1=t1;c2=t2;
//		cout<<"till here "<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<" "<<t1<<" "<<t2<<" "<<t3<<endl;

	if(t3!=c3 && t3!=c4)
	{
//		cout<<"case1"<<endl;
		dorx(t3);
		if(t3==t2);
		else if (r==t2)
		{
			anticlockwise(5);track.push_back(11);
		}
		else if(l==t2)
		{
			clockwise(5);track.push_back(5);
		}
		else
		{
			clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
		}
		dorx(t2);
		if(r==t1)
		{
			anticlockwise(t2);track.push_back(t2+6);
			if(c1>c2)
			{
				int *temp=face_matrix[c2][x[1]].v2;
				c4=assign(temp);			
			}
			else
			{
				int *temp=face_matrix[c2][x[3]].v2;
				c4=assign(temp);
			}
			dorx(c4);
			if(c4==t2);
			else if(r==t2)
			{
				anticlockwise(5);track.push_back(11);
			}
			else if (l==t2)
			{
				clockwise(5);track.push_back(5);
			}
			else
			{
				clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
			}
			clockwise(t2);track.push_back(t2);
		}
		else
		{
			clockwise(t2);track.push_back(t2);
			if(c1>c2)
			{
				int *temp=face_matrix[c2][x[1]].v2;
				c4=assign(temp);			
			}
			else
			{
				int *temp=face_matrix[c2][x[3]].v2;
				c4=assign(temp);
			}
			dorx(c4);
			if(c4==t2);
			else if(r==t2)
			{
				anticlockwise(5);track.push_back(11);
			}
			else if (l==t2)
			{
				clockwise(5);track.push_back(5);
			}
			else
			{
				clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
			}
			anticlockwise(t2);track.push_back(t2+6);
		}
	//	yellow_face(i);
		
	}
	else if(c4==t3)
	{
	//cout<<"case2"<<endl;
	dorx(t3);
	if(t3==t1);
	else if(r==t1)
	{
		anticlockwise(5);track.push_back(11);
	}
	else if (l==t1)
	{
		clockwise(5);track.push_back(5);
	}
	else
	{
		clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
	}
	dorx(t1);
	if(r==t2)
	{anticlockwise(t1);track.push_back(t1+6);
	clockwise(5);track.push_back(5);
	clockwise(t1);track.push_back(t1);
	}
	else
	{clockwise(t1);track.push_back(t1);
	anticlockwise(5);track.push_back(11);
	anticlockwise(t1);track.push_back(t1+6);
	}
//	yellow_face(i);	
	}
	else
	{
	//cout<<"case3"<<endl;
		dorx(t3);
		if(t3==t2);
		else if (r==t2)
		{
			anticlockwise(5);track.push_back(11);
		}
		else if(l==t2)
		{
			clockwise(5);track.push_back(5);
		}
		else
		{
			clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
		}
		dorx(t2);
		if(r==t1)
		{
		anticlockwise(t2);track.push_back(t2+6);
		clockwise(5);track.push_back(5);
		clockwise(t2);track.push_back(t2);		
		}
		else
		{
		clockwise(t2);track.push_back(t2);	
		anticlockwise(5);track.push_back(11);
		anticlockwise(t2);track.push_back(t2+6);
		}
	//	yellow_face(i);
	}
	
}


bool check(int i){
	vector <int> x=set_data(i);
	if(face_matrix[0][i].v2[2]!=-1 ||face_matrix[x[4]][x[5]].v1[2]==-1 )
	return false;
	
	if (i==5)
	{
		if(face_matrix[x[0]][x[1]].v2[0]==1&&face_matrix[x[2]][x[3]].v2[1]==1&&face_matrix[x[4]][x[5]].v2[0]==1&&face_matrix[x[6]][x[7]].v2[1]==1)
		return true ;
		
	}
	else if (i==6)
	{
		if(face_matrix[x[0]][x[1]].v2[1]==1&&face_matrix[x[2]][x[3]].v2[0]==-1 && face_matrix[x[4]][x[5]].v2[1]==1&&face_matrix[x[6]][x[7]].v2[0]==-1)
		return true ;
	}
	else if (i==7)
	{
		if(face_matrix[x[0]][x[1]].v2[1]==-1&&face_matrix[x[2]][x[3]].v2[0]==-1&&face_matrix[x[4]][x[5]].v2[1]==-1&&face_matrix[x[5]][x[6]].v2[0]==-1)
		return true ;
	}
	else if (i==8)
	{
		if(face_matrix[x[0]][x[1]].v2[0]==1&&face_matrix[x[2]][x[3]].v2[1]==-1&&face_matrix[x[4]][x[5]].v2[0]==1&&face_matrix[x[6]][x[7]].v2[1]==-1)
		return true ;
	}
	return false;
}






void finalstep2(vector <int> &track , vector <int> &total_track , vector <int> &fi)
{step=0;track.clear();
	for(int t=1;t<=4;t++)
	{
		//int cop;cin>>cop;
		int i=fi[t]+4;
	//	cout<<"i "<<i<<endl;
		
				vector <int> x=set_data(i);
		int *va=face_matrix[0][i].v1;
		int *vb=face_matrix[x[4]][x[5]].v1;
		if (check(i)==true);//case0
		else if(va[2]==1 && vb[2]==1)//case 1 both on yellow
		{
	//		cout<<"case1"<<endl;
			if(face_matrix[0][i].v2[2]==0)
			yellow_face(i,track);
	
		else if(face_matrix[0][i].v2[2]==1)

	{
	//	cout<<"white on top"<<endl;
		yellow_face_with_white(i,track);
		yellow_face(i,track);
	}
		
	else 
	cout<<"do something"<<endl;	
		}
else if(va[2]==-1&&vb[2]==1)//case2 corner peice in white
		{
			int *tch1=face_matrix[x[0]][x[1]].v2;
			int *tch2=face_matrix[x[2]][x[3]].v2;
			int *tch3=face_matrix[0][i].v2;
			int ch1=assign(tch1),ch2=assign(tch2),ch3=assign(tch3);
		//	cout<<"case2"<<endl;
			int *d;
			if(face_matrix[x[4]][x[5]].v2[2]==1)
				d=face_matrix[x[6]][x[7]].v2;
			else
				d=face_matrix[x[4]][x[5]].v2;
				
			int dg=assign(d);	
			if(face_matrix[0][i].v2[2]==0)
			{
				
				int *temp=face_matrix[0][i].v2;
				int c1=assign(temp);
				if(c1==dg || c1+dg==5);
				else
				{
					if(face_matrix[x[0]][x[1]].v2[2]==0)
					temp=face_matrix[x[0]][x[1]].v2;
					else
					temp=face_matrix[x[2]][x[3]].v2;
					c1=assign(temp);
				}
				
				dorx(c1);
				if(r==ch1 || r==ch2 || r==ch3)
				{
				anticlockwise(c1);track.push_back(c1+6);
				anticlockwise(5);track.push_back(11);
				clockwise(c1);track.push_back(c1);	
				}
				else
				{
					clockwise(c1);track.push_back(c1);
					clockwise(5);track.push_back(5);
					anticlockwise(c1);track.push_back(c1+6);
				}
			}
			else
			{
			int *temp=face_matrix[x[0]][x[1]].v2;
			int c1=assign(temp);
			if(dg==c1 || dg+c1==5);
			else
			{
				temp=face_matrix[x[2]][x[3]].v2;
			}
			c1=assign(temp);
			dorx(c1);
			if(r==ch1 || r==ch2)
				{
				anticlockwise(c1);track.push_back(c1+6);
				anticlockwise(5);track.push_back(11);
				clockwise(c1);track.push_back(c1);	
				}
				else
				{
					clockwise(c1);track.push_back(c1);
					clockwise(5);track.push_back(5);
					anticlockwise(c1);track.push_back(c1+6);
				}
					
			}
			
		t--;	
		}
		else if(va[2]==1&&vb[2]==0)//case 3
		{
		//	cout<<"case3"<<endl;
			int *demp1=face_matrix[x[0]][x[1]].v2;
			int *demp2=face_matrix[x[2]][x[3]].v2;		
			int *demp3=face_matrix[0][i].v2;		
			int dc1=assign(demp1);
			int dc2=assign(demp2);
			int dc3=assign(demp3);
			int *temp1=face_matrix[x[4]][x[5]].v2;
			int *temp2=face_matrix[x[6]][x[7]].v2;			
			int tc1=assign(temp1);
			int tc2=assign(temp2);
			int c1=-1;
			if(tc1==dc1 || tc1==dc2 || tc1==dc3)
			c1=tc1;
			else if (tc2==dc1 || tc2==dc2 || tc2==dc3)
			c1=tc2;
			
			if (c1!=-1)
			{
				dorx(c1);
			if(r==tc1 || r==tc2)
				{
				anticlockwise(c1);track.push_back(c1+6);
				anticlockwise(5);track.push_back(11);
				clockwise(c1);track.push_back(c1);	
				}
				else
				{
					clockwise(c1);track.push_back(c1);
					clockwise(5);track.push_back(5);
					anticlockwise(c1);track.push_back(c1+6);
				}
					
			}
			else
			{
				c1=tc1;
				dorx(c1);
			if(r==tc1 || r==tc2)
				{
				anticlockwise(c1);track.push_back(c1+6);
				clockwise(5);track.push_back(5);
				clockwise(c1);track.push_back(c1);	
				}
				else
				{
					clockwise(c1);track.push_back(c1);
					anticlockwise(5);track.push_back(11);
					anticlockwise(c1);track.push_back(c1+6);
				}
					
			}
			
			
		t--;	
			
		}
		else
		{
		//	cout<<"case4"<<endl;
			//cout<<"va "<<va[0]<<" "<<va[1]<<" "<<va[2]<<endl<<" vb "<<vb[0]<<" "<<vb[1]<<" "<<vb[2]<<endl;
			int *temp=face_matrix[x[4]][x[5]].v2;
			int c1=assign(temp);
			dorx(c1);
		//	cout<<"c1 "<<c1<<"r "<<r<<"x6 "<<x[6]<<l<<endl;
			int *temp1=face_matrix[x[6]][x[7]].v2;
			int ch=assign(temp1);
			if(r==ch)
				{
				anticlockwise(c1);track.push_back(c1+6);
				anticlockwise(5);track.push_back(11);
				clockwise(c1);track.push_back(c1);	
				}
				else
				{
					clockwise(c1);track.push_back(c1);
					clockwise(5);track.push_back(5);
					anticlockwise(c1);track.push_back(c1+6);
				}
			t--;	
		}
	//	printallfaces();
	}
	cout<<"track size "<<track.size()<<" no. of steps in f2l "<<step<<endl;
	for(int ii=0;ii<track.size();ii++)
	{cout<<track[ii]<<" ";
	total_track.push_back(track[ii]);
	}
	cout<<endl;

}




	
void step2(vector <int> &track , vector <int> &total_track)
{
	vector <int> count;
	int s[24][5]={{-1,1,2,3,4},{-1,1,2,4,3},{-1,1,3,2,4},{-1,1,3,4,2},{-1,1,4,3,2},{-1,1,4,2,3},
			  {-1,2,3,4,1},{-1,2,3,1,4},{-1,2,4,1,3},{-1,2,4,3,1},{-1,2,3,1,4},{-1,2,3,4,1},
			  {-1,3,4,1,2},{-1,3,4,2,1},{-1,3,1,2,4},{-1,3,1,4,2},{-1,3,2,1,4},{-1,3,2,4,1},
			  {-1,4,1,2,3},{-1,4,1,3,2},{-1,4,2,1,3},{-1,4,2,3,1},{-1,4,3,1,2},{-1,4,3,2,1}};
for(int j=0;j<24;j++)
{
	track.clear();step=0;
//	cout<<"j "<<j<<endl;
	//int cop;cin>>cop;
	int *aa=s[j];int a[5]={aa[0],aa[1]+4,aa[2]+4,aa[3]+4,aa[4]+4};
	for(int t=1;t<=4;t++)
	{
		
		int i=a[t];
	//	cout<<"i "<<i<<endl;
		vector <int> x=set_data(i);
		int *va=face_matrix[0][i].v1;
		int *vb=face_matrix[x[4]][x[5]].v1;
		if (check(i)==true);//case0
		if(va[2]==1 && vb[2]==1)//case 1 both on yellow
		{
//			cout<<"case1"<<endl;
			if(face_matrix[0][i].v2[2]==0)
			yellow_face(i,track);
	
		else if(face_matrix[0][i].v2[2]==1)

	{
	//	cout<<"white on top"<<endl;
		yellow_face_with_white(i,track);
		yellow_face(i,track);
	}
		
	else 
	cout<<"do something"<<endl;	
		}
		else if(va[2]==-1&&vb[2]==1)//case2 corner peice in white
		{
			int *tch1=face_matrix[x[0]][x[1]].v2;
			int *tch2=face_matrix[x[2]][x[3]].v2;
			int *tch3=face_matrix[0][i].v2;
			int ch1=assign(tch1),ch2=assign(tch2),ch3=assign(tch3);
		//	cout<<"case2"<<endl;
			int *d;
			if(face_matrix[x[4]][x[5]].v2[2]==1)
				d=face_matrix[x[6]][x[7]].v2;
			else
				d=face_matrix[x[4]][x[5]].v2;
				
			int dg=assign(d);	
			if(face_matrix[0][i].v2[2]==0)
			{
				
				int *temp=face_matrix[0][i].v2;
				int c1=assign(temp);
				if(c1==dg || c1+dg==5);
				else
				{
					if(face_matrix[x[0]][x[1]].v2[2]==0)
					temp=face_matrix[x[0]][x[1]].v2;
					else
					temp=face_matrix[x[2]][x[3]].v2;
					c1=assign(temp);
				}
				
				dorx(c1);
				if(r==ch1 || r==ch2 || r==ch3)
				{
				anticlockwise(c1);track.push_back(c1+6);
				anticlockwise(5);track.push_back(11);
				clockwise(c1);track.push_back(c1);	
				}
				else
				{
					clockwise(c1);track.push_back(c1);
					clockwise(5);track.push_back(5);
					anticlockwise(c1);track.push_back(c1+6);
				}
			}
			else
			{
			int *temp=face_matrix[x[0]][x[1]].v2;
			int c1=assign(temp);
			if(dg==c1 || dg+c1==5);
			else
			{
				temp=face_matrix[x[2]][x[3]].v2;
			}
			c1=assign(temp);
			dorx(c1);
			if(r==ch1 || r==ch2)
				{
				anticlockwise(c1);track.push_back(c1+6);
				anticlockwise(5);track.push_back(11);
				clockwise(c1);track.push_back(c1);	
				}
				else
				{
					clockwise(c1);track.push_back(c1);
					clockwise(5);track.push_back(5);
					anticlockwise(c1);track.push_back(c1+6);
				}
					
			}
			
		t--;	
		}
		else if(va[2]==1&&vb[2]==0)//case 3
		{
//			cout<<"case3"<<endl;
			int *demp1=face_matrix[x[0]][x[1]].v2;
			int *demp2=face_matrix[x[2]][x[3]].v2;		
			int *demp3=face_matrix[0][i].v2;		
			int dc1=assign(demp1);
			int dc2=assign(demp2);
			int dc3=assign(demp3);
			int *temp1=face_matrix[x[4]][x[5]].v2;
			int *temp2=face_matrix[x[6]][x[7]].v2;			
			int tc1=assign(temp1);
			int tc2=assign(temp2);
			int c1=-1;
			if(tc1==dc1 || tc1==dc2 || tc1==dc3)
			c1=tc1;
			else if (tc2==dc1 || tc2==dc2 || tc2==dc3)
			c1=tc2;
			
			if (c1!=-1)
			{
				dorx(c1);
			if(r==tc1 || r==tc2)
				{
				anticlockwise(c1);track.push_back(c1+6);
				anticlockwise(5);track.push_back(11);
				clockwise(c1);track.push_back(c1);	
				}
				else
				{
					clockwise(c1);track.push_back(c1);
					clockwise(5);track.push_back(5);
					anticlockwise(c1);track.push_back(c1+6);
				}
					
			}
			else
			{
				c1=tc1;
				dorx(c1);
			if(r==tc1 || r==tc2)
				{
				anticlockwise(c1);track.push_back(c1+6);
				clockwise(5);track.push_back(5);
				clockwise(c1);track.push_back(c1);	
				}
				else
				{
					clockwise(c1);track.push_back(c1);
					anticlockwise(5);track.push_back(11);
					anticlockwise(c1);track.push_back(c1+6);
				}
					
			}
			
			
		t--;	
			
		}
		else
		{
//			cout<<"case4"<<endl;
			//cout<<"va "<<va[0]<<" "<<va[1]<<" "<<va[2]<<endl<<" vb "<<vb[0]<<" "<<vb[1]<<" "<<vb[2]<<endl;
			int *temp=face_matrix[x[4]][x[5]].v2;
			int c1=assign(temp);
			dorx(c1);
		//	cout<<"c1 "<<c1<<"r "<<r<<"x6 "<<x[6]<<l<<endl;
			int *temp1=face_matrix[x[6]][x[7]].v2;
			int ch=assign(temp1);
			if(r==ch)
				{
				anticlockwise(c1);track.push_back(c1+6);
				anticlockwise(5);track.push_back(11);
				clockwise(c1);track.push_back(c1);	
				}
				else
				{
					clockwise(c1);track.push_back(c1);
					clockwise(5);track.push_back(5);
					anticlockwise(c1);track.push_back(c1+6);
				}
			t--;	
		}

	//printallfaces();	
	}
	//cout<<"track size "<<track.size()<<" step "<<step<<endl;
	//for(int ii=0;ii<track.size();ii++)
	//cout<<track[ii]<<" ";
	//cout<<endl;
	count.push_back(step);
step=0;
//	printallfaces();
	//cout<<endl;
	reverse(track);
	step=0;
//printallfaces();
//	int tt;cin>>tt;
}
int min=min_element(count.begin(),count.end())-count.begin();
//cout<<"min "<<count[min]<<endl;
vector <int> fi;
fi.push_back(s[min][0]);fi.push_back(s[min][1]);fi.push_back(s[min][2]);fi.push_back(s[min][3]);fi.push_back(s[min][4]);
track.clear();
finalstep2(track,total_track,fi);

}


void yellow_cross_with_line(vector <int> &block,vector <int> &track,vector <int> &total_track){
	track.clear();
	//line
	if(block[0]==2){
		clockwise(1);track.push_back(1);
		clockwise(2);track.push_back(2);
		clockwise(5);track.push_back(5);
		anticlockwise(2);track.push_back(2+6);
		anticlockwise(5);track.push_back(5+6);
		anticlockwise(1);track.push_back(1+6);
	}
	else if(block[0]==1){
		clockwise(2);track.push_back(2);
		clockwise(4);track.push_back(4);
		clockwise(5);track.push_back(5);
		anticlockwise(4);track.push_back(4+6);
		anticlockwise(5);track.push_back(5+6);
		anticlockwise(2);track.push_back(2+6);
	}
	for(int tr=0;tr<track.size();tr++)
	{
		cout<<track[tr]<<" ";
		total_track.push_back(track[tr]);

	}
}

void yellow_l(vector <int> &track,vector <int> &total_track){
	track.clear();
	vector <int> block;
	int fcol1,fcol2,x;
	for(int i=1;i<=4;i++){
		if(face_matrix[5][i].v2[2]==1){
			if(face_matrix[5][i].v1[0]==1){
				x=3;
			}
			else if(face_matrix[5][i].v1[0]==-1){
				x=1;
			}
			else if(face_matrix[5][i].v1[1]==1){
				x=2;
			}
			else if(face_matrix[5][i].v1[1]==-1){
				x=4;
			}
			block.push_back(x);
		}
	}
	sort(block.begin(),block.end());
	if(block[0]==1 && block[1]==4){
		fcol1=1;
		fcol2=2;
	}
	else if(block[0]==1 && block[1]==2){
		fcol1=3;
		fcol2=1;
	}
	else if(block[0]==2 && block[1]==3){
		fcol1=4;
		fcol2=3;
	}
	else if(block[0]==3 && block[1]==4){
		fcol1=2;
		fcol2=4;
	}
	clockwise(fcol1);track.push_back(fcol1);
	clockwise(5);track.push_back(5);
	clockwise(fcol2);track.push_back(fcol2);
	anticlockwise(5);track.push_back(5+6);
	anticlockwise(fcol2);track.push_back(fcol2+6);
	anticlockwise(fcol1);track.push_back(fcol1+6);
	for(int tr=0;tr<track.size();tr++)
	{
		cout<<track[tr]<<" ";
		total_track.push_back(track[tr]);

	}
}

void yellow_cross(vector <int> &track,vector <int> &total_track){
	track.clear();
	vector <int> block;
	int fcol1,fcol2,x;
	for(int i=1;i<=4;i++){
		if(face_matrix[5][i].v2[2]==1){
			if(face_matrix[5][i].v1[0]==1){
				x=3;
			}
			else if(face_matrix[5][i].v1[0]==-1){
				x=1;
			}
			else if(face_matrix[5][i].v1[1]==1){
				x=2;
			}
			else if(face_matrix[5][i].v1[1]==-1){
				x=4;
			}
			block.push_back(x);
			cout << x << " ";
		}
	}
	sort(block.begin(),block.end());
	cout << "block size " <<  block.size() << endl;
	if(block.size()==0 || block.size()==1){
		//yellow-dot
		clockwise(1);track.push_back(1);
		clockwise(2);track.push_back(2);
		clockwise(5);track.push_back(5);
		anticlockwise(2);track.push_back(2+6);
		anticlockwise(5);track.push_back(5+6);
		anticlockwise(1);track.push_back(1+6);
		
		
		//l-shape
		for(int tr=0;tr<track.size();tr++)
		{
			cout<<track[tr]<<" ";
			total_track.push_back(track[tr]);

		}
//	cout<<endl<<"no of steps"<<step<<endl;
		yellow_l(track,total_track);
		
	}
	else if(block.size()==2){
		if((block[1]-block[0])==2){
			yellow_cross_with_line(block,track,total_track);
		}
		else{
			//l-shape
			yellow_l(track,total_track);
			
		}
	}
	else if(block.size()==3){
		//l-shape
		yellow_l(track,total_track);
	}
	
	
	
}



//oll
void yellow_cross_only_case21(int c,vector <int> &track)
{
	//R U2 R' U' R U R' U' R U' R'
	dorx(c);
	int r1=r;
	clockwise(r1);track.push_back(r1);
	clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
	anticlockwise(r1);track.push_back(r1+6);
	anticlockwise(5);track.push_back(11);
	clockwise(r1);track.push_back(r1);
	clockwise(5);track.push_back(5);
	anticlockwise(r1);track.push_back(r1+6);
	anticlockwise(5);track.push_back(11);
	clockwise(r1);track.push_back(r1);
	anticlockwise(5);track.push_back(11);
	anticlockwise(r1);track.push_back(r1+6);
}
void yellow_cross_only_case22(int c,vector <int> &track)
{
	//	R U2' [R2 U'] [R2 U'] R2 U2' R
	dorx(c);
	int r1=r;
	clockwise(r1);track.push_back(r1);
	anticlockwise(5);track.push_back(11);anticlockwise(5);track.push_back(11);
	clockwise(r1);track.push_back(r1);clockwise(r1);track.push_back(r1);
	anticlockwise(5);track.push_back(11);
	clockwise(r1);track.push_back(r1);clockwise(r1);track.push_back(r1);
	anticlockwise(5);track.push_back(11);
	clockwise(r1);track.push_back(r1);clockwise(r1);track.push_back(r1);
	anticlockwise(5);track.push_back(11);anticlockwise(5);track.push_back(11);
	clockwise(r1);track.push_back(r1);
}
void yellow_cross_only_case23(int c,vector <int> &track)
{//	R2 D [R' U2 R] D' [R' U2 R']
	dorx(c);int r1=r;int d=0;
	clockwise(r1);track.push_back(r1);clockwise(r1);track.push_back(r1);
	clockwise(d);track.push_back(d);
	anticlockwise(r1);track.push_back(r1+6);
	clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
	clockwise(r1);track.push_back(r1);
	anticlockwise(d);track.push_back(d+6);
	anticlockwise(r1);track.push_back(r1+6);
	clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
	anticlockwise(r1);track.push_back(r1+6);
	
}
void yellow_cross_only_case24(int c,vector <int> &track)
{//L F R' F' L' F R F'
	dorx(c);int r1=r;int l1=l;
	clockwise(l1);track.push_back(l1);
	clockwise(c);track.push_back(c);
	anticlockwise(r1);track.push_back(r1+6);
	anticlockwise(c);track.push_back(c+6);
	anticlockwise(l1);track.push_back(l1+6);
	clockwise(c);track.push_back(c);
	clockwise(r1);track.push_back(r1);
	anticlockwise(c);track.push_back(c+6);
}
void yellow_cross_only_case25(int c,vector <int> &track)
{//[R' F R B'] [R' F' R B]
	dorx(c);int r1=r;int b=abs(5-c);
	anticlockwise(r1);track.push_back(r1+6);
	clockwise(c);track.push_back(c);
	clockwise(r1);track.push_back(r1);
	anticlockwise(b);track.push_back(b+6);
	anticlockwise(r1);track.push_back(r1+6);
	anticlockwise(c);track.push_back(c+6);
	clockwise(r1);track.push_back(r1);
	clockwise(b);track.push_back(b);
	
}

void yellow_cross_only_case26(int c,vector <int> &track)
{//	R' U' R U' R' U2 R
	dorx(c);int r1=r;
	anticlockwise(r1);track.push_back(r1+6);
	anticlockwise(5);track.push_back(11);
	clockwise(r1);track.push_back(r1);
	anticlockwise(5);track.push_back(11);
	anticlockwise(r1);track.push_back(r1+6);
	clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
	clockwise(r1);track.push_back(r1);

	
}
void yellow_cross_only_case27(int c,vector <int> &track)
{
	//L U L' U [L U2 L']
	dorx(c);int l1=l;
	clockwise(l1);track.push_back(l1);
	clockwise(5);track.push_back(5);
	anticlockwise(l1);track.push_back(l1+6);
	clockwise(5);track.push_back(5);
	clockwise(l1);track.push_back(l1);
	clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
	anticlockwise(l1);track.push_back(l1+6);
}
void oll(vector <int> &track , vector <int> &total_track)
{cout<<"OLL"<<endl;
	int *v1=face_matrix[5][1].v2;
	int *v2=face_matrix[5][2].v2;
	int *v3=face_matrix[5][3].v2;
	int *v4=face_matrix[5][4].v2;	
	int *v5=face_matrix[5][5].v2;
	int *v6=face_matrix[5][6].v2;
	int *v7=face_matrix[5][7].v2;
	int *v8=face_matrix[5][8].v2;
	//corner peice yellow axis
	int c1=assign(v5);int c2=assign(v6);int c3=assign(v7);int c4=assign(v8);
		
	if (v5[2]==1 && v6[2]==1 && v7[2]==1 && v8[2]==1);//correct
	else if (v5[2]==0 && v6[2]==0 && v7[2]==0 && v8[2]==0)//yellow cross only
	{cout<<"yellow cross"<<endl;
		if (c1+c2+c3+c4 == 10)//case21
		{cout<<"case21"<<endl;
			yellow_cross_only_case21(c1,track);
		}
		else//case 22
		{cout<<"case22"<<endl;
			int c;
			if(c1==c2 || c1==c3 || c1==c4)
			c=c1;
			else if (c2==c3 || c2==c4)
			c=c2;
			else if (c3==c4)
			c=c3;
			dorx(c);int f=r;
			yellow_cross_only_case22(f,track)	;		
			
		}
		
	}
	else if(v5[2]+v6[2]+v7[2]+v8[2]==1)//5 yellow sticker
	{
		int *a;int f;
		if (v5[2]==1)
		a=face_matrix[5][5].v1;
		else if (v6[2]==1)
		a=face_matrix[5][6].v1;
		else if (v7[2]==1)
		a=face_matrix[5][7].v1;
		else if (v8[2]==1)
		a=face_matrix[5][8].v1;
		int aa[3]={a[0],0,0};
		int ab[3]={0,a[1],0};
		int aac=assign(aa);int abc=assign(ab);
		if(aac==c1 || aac==c2 || aac==c3 || aac==c4)
		f=aac;
		else 
		f=abc;
		dorx(f);
		if (r==c1 || r==c2 || r==c3 || r==c4)//case 27
		{
			f=abs(5-f);
			yellow_cross_only_case27(f,track);
		}
		else// case 26
		{
			f=abs(5-f);
			yellow_cross_only_case26(f,track);
		}
	}
	else // 6 yellow sticker
	{
		if(c1+c2+c3+c4==15)//case 24
		{
			vector <int> a;
			int c;
			if (c1==5)
			a.push_back(5);
			if (c2==5)
			a.push_back(6);
			if (c3==5)
			a.push_back(7);
			if (c4==5) 
			a.push_back(8);
			int *av1=face_matrix[5][a[0]].v1;int *av2=face_matrix[5][a[1]].v1;
			if(av1[0]==av2[0])
			{
				int aa[3]={av1[0],0,0};
				c=assign(aa);
			}
			else
			{
				int aa[3]={0,av1[1],0};
				c=assign(aa);	
			}
			dorx(c);
			int f=r;f=abs(5-f);
			yellow_cross_only_case24(f,track);
		}
		else if (  (c1==c2&&c3==c4) ||  (c1==c3&&c2==c4) ||  (c1==c4&&c3==c2) )// case 23
		{
			int f = (c1+c2+c3+c4-10)/2;
			yellow_cross_only_case23(f,track);
			
		}
		else // case 25
		{int f;
			if(c1==5)
			{
				int *ac=face_matrix[5][5].v1;
				int aa[3]={ac[0],0,0};
				int ab[3]={0,ac[1],0};
				int aac=assign(aa);int abc=assign(ab);
				if(aac!=c2 && aac!=c3 && aac!=c4)
				{dorx(aac);
				f=r;
				if(r==abc)
				{dorx(abc);
				f=r;
				}
				yellow_cross_only_case25(f,track);
				return ;
				}
			}
			if(c2==5)
			{
				int *ac=face_matrix[5][6].v1;
				int aa[3]={ac[0],0,0};
				int ab[3]={0,ac[1],0};
				int aac=assign(aa);int abc=assign(ab);
				if(aac!=c1 && aac!=c3 && aac!=c4)
				{dorx(aac);
				f=r;
				if(r==abc)
				{dorx(abc);
				f=r;
				}
				yellow_cross_only_case25(f,track);
				return;
				}
			}
			if(c3==5)
			{
				int *ac=face_matrix[5][7].v1;
				int aa[3]={ac[0],0,0};
				int ab[3]={0,ac[1],0};
				int aac=assign(aa);int abc=assign(ab);
				if(aac!=c2 && aac!=c1 && aac!=c4)
				{
				dorx(aac);
				f=r;
				if(r==abc)
				{dorx(abc);
				f=r;
				}
				yellow_cross_only_case25(f,track);
				return;
				}
			}
			 if(c4==5)
			{
				int *ac=face_matrix[5][8].v1;
				int aa[3]={ac[0],0,0};
				int ab[3]={0,ac[1],0};
				int aac=assign(aa);int abc=assign(ab);
				if(aac!=c2 && aac!=c3 && aac!=c1)
				{dorx(aac);
				f=r;
				if(r==abc)
				{dorx(abc);
				f=r;
				}
				yellow_cross_only_case25(f,track);
				return;
				}
			}
		//	dorx(f);
			//f=l;
		//	cout<<"face "<<f<<endl;
		yellow_cross_only_case25(f,track);	
		}
	}
	cout<<"no. steps for yellow face "<<track.size()<<endl;
	for(int o=0;o<track.size();o++)
	{
		cout<<track[o]<<" ";
		total_track.push_back(track[o]);
	}
	
}



void pll(vector <int> &track , vector <int> &total_track){
	track.clear();
	if(((face_matrix[1][5].v2[0]==face_matrix[1][8].v2[0]) && (face_matrix[1][5].v2[1]==face_matrix[1][8].v2[1])) && ((face_matrix[2][5].v2[0]==face_matrix[2][8].v2[0]) && (face_matrix[2][5].v2[1]==face_matrix[2][8].v2[1])) && ((face_matrix[3][5].v2[0]==face_matrix[3][8].v2[0]) && (face_matrix[3][5].v2[1]==face_matrix[3][8].v2[1])) && ((face_matrix[4][5].v2[0]==face_matrix[4][8].v2[0]) && (face_matrix[4][5].v2[1]==face_matrix[4][8].v2[1])));
	
	else if(((face_matrix[1][5].v2[0]==face_matrix[1][8].v2[0]) && (face_matrix[1][5].v2[1]==face_matrix[1][8].v2[1])) || ((face_matrix[2][5].v2[0]==face_matrix[2][8].v2[0]) && (face_matrix[2][5].v2[1]==face_matrix[2][8].v2[1])) || ((face_matrix[3][5].v2[0]==face_matrix[3][8].v2[0]) && (face_matrix[3][5].v2[1]==face_matrix[3][8].v2[1])) || ((face_matrix[4][5].v2[0]==face_matrix[4][8].v2[0]) && (face_matrix[4][5].v2[1]==face_matrix[4][8].v2[1])))
	{	//adjacent corner swap
		int l,f,r;
		if((face_matrix[1][5].v2[0]==face_matrix[1][8].v2[0]) && (face_matrix[1][5].v2[1]==face_matrix[1][8].v2[1])){
			l=assign(face_matrix[1][5].v2);
		}
		else if((face_matrix[2][5].v2[0]==face_matrix[2][8].v2[0]) && (face_matrix[2][5].v2[1]==face_matrix[2][8].v2[1])){
			l=assign(face_matrix[2][5].v2);
		}
		else if((face_matrix[3][5].v2[0]==face_matrix[3][8].v2[0]) && (face_matrix[3][5].v2[1]==face_matrix[3][8].v2[1])){
			l=assign(face_matrix[3][5].v2);
		}
		else if((face_matrix[4][5].v2[0]==face_matrix[4][8].v2[0]) && (face_matrix[4][5].v2[1]==face_matrix[4][8].v2[1])){
			l=assign(face_matrix[4][5].v2);
		}
		
		
		dor(l);
		f=right1;
		dor(f);
		r=right1;
		
		clockwise(r);track.push_back(r);
    	clockwise(5);track.push_back(5);
    	anticlockwise(r);track.push_back(r+6);
    	anticlockwise(5);track.push_back(5+6);
    	anticlockwise(r);track.push_back(r+6);
    	clockwise(f);track.push_back(f);
    	clockwise(r);track.push_back(r);
		clockwise(r);track.push_back(r);
//    	anticlockwise(1);
//    	anticlockwise(3);

		anticlockwise(5);track.push_back(5+6);
		anticlockwise(r);track.push_back(r+6);
		anticlockwise(5);track.push_back(5+6);
		clockwise(r);track.push_back(r);
		clockwise(5);track.push_back(5);
		anticlockwise(r);track.push_back(r+6);
		anticlockwise(f);track.push_back(f+6);
		
    }
    else{
    	//Diagonal Swap
    	clockwise(3);track.push_back(3);
    	clockwise(1);track.push_back(1);
    	anticlockwise(5);track.push_back(5+6);
    	anticlockwise(1);track.push_back(1+6);
    	anticlockwise(5);track.push_back(5+6);
    	clockwise(1);track.push_back(1);
    	clockwise(5);track.push_back(5);
    	anticlockwise(1);track.push_back(1+6);
    	anticlockwise(3);track.push_back(3+6);
    	
    	clockwise(1);track.push_back(1);
    	clockwise(5);track.push_back(5);
    	anticlockwise(1);track.push_back(1+6);
    	anticlockwise(5);track.push_back(5+6);
    	anticlockwise(1);track.push_back(1+6);
    	clockwise(3);track.push_back(3);
    	clockwise(1);track.push_back(1);
    	anticlockwise(3);track.push_back(3+6);
    	
	}
	if(face_matrix[1][5].v2[0]==-1){
		clockwise(5);track.push_back(5);
		clockwise(5);track.push_back(5);
	}
	else if(face_matrix[1][5].v2[1]==-1){
		anticlockwise(5);track.push_back(5+6);
	}
	else if(face_matrix[1][5].v2[1]==1){
		clockwise(5);track.push_back(5);
	}
	
	cout<<"no. steps for yellow corners "<<track.size()<<endl;
	for(int o=0;o<track.size();o++)
	{
		cout<<track[o]<<" ";
		total_track.push_back(track[o]);
	}
}



//last step
void algo1(int cc,vector <int> &track)
{cout<<"algo 1"<<endl;
	//R2 U (R U R' U') R' U' (R' U R')
	dorx(cc);int r1=r;
	clockwise(r1);track.push_back(r1);clockwise(r1);track.push_back(r1);
	clockwise(5);track.push_back(5);
	clockwise(r1);track.push_back(r1);
	clockwise(5);track.push_back(5);
	anticlockwise(r1);track.push_back(r1+6);
	anticlockwise(5);track.push_back(11);
	anticlockwise(r1);track.push_back(r1+6);
	anticlockwise(5);track.push_back(11);
	anticlockwise(r1);track.push_back(r1+6);
	clockwise(5);track.push_back(5);
	anticlockwise(r1);track.push_back(r1+6);
}

void algo2(int c,vector <int> &track )
{
	cout<<"algo2"<<endl;
	//(R U' R U) R U (R U' R' U') R2
	dorx(c);
	int r1=r;
	clockwise(r1);track.push_back(r1);
	anticlockwise(5);track.push_back(11);
	clockwise(r1);track.push_back(r1);
	clockwise(5);track.push_back(5);
	clockwise(r1);track.push_back(r1);
	clockwise(5);track.push_back(5);
	clockwise(r1);track.push_back(r1);
	anticlockwise(5);track.push_back(11);
	anticlockwise(r1);track.push_back(r1+6);
	anticlockwise(5);track.push_back(11);
	clockwise(r1);track.push_back(r1);clockwise(r1);track.push_back(r1);
}

void algo3(int c,vector <int> &track )//H
{
	//R2 U2 R U2 R2 U2 R2 U2 R U2 R2
	dorx(c);int r1=r;
	clockwise(r1);track.push_back(r1);clockwise(r1);track.push_back(r1);
	clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
	clockwise(r1);track.push_back(r1);
	clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
	clockwise(r1);track.push_back(r1);clockwise(r1);track.push_back(r1);
	clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
	clockwise(r1);track.push_back(r1);clockwise(r1);track.push_back(r1);
	clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
	clockwise(r1);track.push_back(r1);
	//clockwise(r1);track.push_back(r1);clockwise(r1);track.push_back(r1);
	clockwise(5);track.push_back(5);clockwise(5);track.push_back(5);
	clockwise(r1);track.push_back(r1);clockwise(r1);track.push_back(r1);
}
void algo4(int c,vector <int> &track )//Z
{
	//R' U' R' F R F' U R F' U' L' U L F
	dorx(c);int r1=r;int l1=l;
	anticlockwise(r1);track.push_back(r1+6);
	anticlockwise(5);track.push_back(11);
	anticlockwise(r1);track.push_back(r1+6);
	clockwise(c);track.push_back(c);
	clockwise(r1);track.push_back(r1);
	anticlockwise(c);track.push_back(c+6);
	clockwise(5);track.push_back(5);
	clockwise(r1);track.push_back(r1);
	anticlockwise(c);track.push_back(c+6);
	anticlockwise(5);track.push_back(11);
	anticlockwise(l1);track.push_back(l1+6);
	clockwise(5);track.push_back(5);
	clockwise(l1);track.push_back(l1);
	clockwise(c);track.push_back(c);

}

void last_step(vector <int> &track ,vector <int> &total_track )
{track.clear();step=0;
	int f;
	int *v1=face_matrix[5][1].v1;
	int *v2=face_matrix[5][2].v1;
	int *v3=face_matrix[5][3].v1;
	int *v4=face_matrix[5][4].v1;
	if(v1[0]==-1 && v2[1]==1 && v3[0]==1 && v4[1]==-1)	;
	
	else if(v1[0]==-1 || v2[1]==1 || v3[0]==1 || v4[1]==-1)//one face done
	{
		if (v1[0]==-1)//orange
	{
		f=1;
	}
	else if (v2[1]==1)//green
	{
		f=3;
	}
	else if (v3[0]==1)//red
	{
		f=4;
	}
	else if (v4[1]==-1)//blue
	{
		f=2;
	}
	step=0;
	cout<<"f "<<f<<endl;
	algo1(f,track);
	 v1=face_matrix[5][1].v1;
	 v2=face_matrix[5][2].v1;
	 v3=face_matrix[5][3].v1;
	 v4=face_matrix[5][4].v1;
	if(v1[0]!=-1 || v2[1]!=1 || v3[0]!=1 || v4[1]!=-1)
	{reverse(track);
	track.clear();step=0;
	algo2(f,track);
	}
	}
	else
	{
		//cout<<v1[0]<<" "<< v1[1]<<" "<< v1[2]<<" "<<v4[1]<<endl;
		if(v1[0]==1 && v3[0]==-1 && v2[1]==-1 && v4[1]==1)//H permutation
		{
			cout<<"h"<<endl;
			f=1;algo3(f,track);
		}
		else if(v1[1]==-1 && v3[1]==1 && v2[0]==1 && v4[0]==-1)//Z permutation
		{
			cout<<"z1"<<endl;
			f=1;algo4(f,track);
		}
		else if(v1[1]==1 && v3[1]==-1 && v2[0]==-1 && v4[0]==1)
		{
			cout<<"z2"<<endl;
			f=3;algo4(f,track);
		}
		else
		{
			cout<<"NO CASE "<<endl;
		}
	}
	cout<<"no. of steps for last step= "<<track.size()<<endl;
	for(int k=0;k<track.size();k++)
	{
		cout<<track[k]<<" ";
		total_track.push_back(track[k]);
	}
	cout<<endl;

}



int main(){
	//colorinput();
	face_color();
	for(int i=0;i<6;i++)
	{
		for (int j=0;j<9;j++)
		cout<<color[i][j]<<" ";
		cout<<endl;
	}
	
	sb block[3][3][3];
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				for(int vv=0;vv<3;vv++)
				block[i][j][k].c[vv]=-1;
			}
		}
	}
	
	block_matrix(block);

	face(block);
	

cout<<endl;
vector <int> total_track;
	printallfaces();
	cout<<"give input to shuffle else type 6"<<endl;vector<int> temp;
	int in;cin>>in;
	while(in<6){
		clockwise(in);temp.push_back(in);
		cin>>in;
	}
	step=0;
	
	step1(total_track);
	cout<<"white cross"<<endl;
	printallfaces();	
	vector<int> track;

step2(track,total_track);
cout<<"f2l"<<endl;
printallfaces();
cout<<endl<<"total steps till now white cross+ f2l= "<<total_track.size()<<endl;

yellow_cross(track,total_track);
cout<<endl;
printallfaces();
cout<<endl<<"total steps till now white cross+ f2l+yellow cross= "<<total_track.size()<<endl;
step=0;track.clear();
oll(track,total_track);
cout<<endl;
printallfaces();
cout<<endl<<"total steps till now white cross+ f2l+yellow cross+yellow face= "<<total_track.size()<<endl;
track.clear();
pll(track,total_track);
cout<<endl;
printallfaces();
cout<<endl<<"total steps till now white cross+ f2l+yellow cross+yellow face+ yellow corners= "<<total_track.size()<<endl; 
last_step(track,total_track);
cout<<endl;
printallfaces();

cout<<endl<<"total steps to complete cube= "<<total_track.size()<<endl; 



}
