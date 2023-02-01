#include<iostream>

using namespace std;

int i, j, xx, yy, pc, ans = 0;
char map[12][6];
bool ch[12][6];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

//아래가 비어있는데 바로 위가 뿌요라면 아래를 뿌요로 바꾸고 위를 비움 
void fall()
{
  for(int r = 0; r < 6; r++)
    {
      while(1)
        {
          bool np = true;

          for(int l = 10; l >= 0; l--)
            {
              if(map[l][r] != '.' && map[l+1][r] == '.')
              {
                map[l+1][r] = map[l][r];
                map[l][r] = '.';
                np = false;
              }
            }
          if(np) break;
        }
    }
}

//저장해둔 ch배열 위치와 같은 map자료를 삭제
void del()
{
  for(int v = 0; v < 12; i++)
  {
    for(int w = 0; w < 6; w++)
    {
      if(ch[v][w]) map[v][w] = '.';
    } 
  }
}

//뿌요가 걸리면 dfs로 갯수 찾으면서 ch배열에 같은 위치를 체크
void dfs(int a, int b, char col)
{
  ch[a][b] = true;
  
  for(int c = 0; c < 4; c++)
    {     
      xx = a + dx[c];
      yy = b + dy[c];

      if(xx >= 0 && yy >= 0 && xx < 12 && yy < 6)
        {
          if(map[xx][yy] == col)
          {
            pc++;
            dfs(xx, yy, col);
          }
        }
    }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  freopen("input.txt","rt", stdin);
  
  //받기
  for(i = 0; i < 12; i++)
    for(j = 0; j < 6; j++) 
      cin >> map[i][j];

  //뿌요 탐색
  while(1)
  {
    bool NP = true;

    for(i = 11; i >= 0; i--)
      {
        for(j = 5; j >= 0; j--)
        {
          if(map[i][j] != '.')
          {
            pc = 1;
            dfs(i, j, map[i][j]);
          
            //4개 이상 탐색시    
            if(pc >= 4)
            {
              del();
              NP = false;
            }
          }
        }
      }
    
      if(NP) break; // 정상완료되면 종료
      fall();
      ans++;
    
  for(i = 0; i < 12; i++)
    for(j = 0; j < 6; j++) 
      ch[i][j] = false;
  }
  
  cout << ans;
}