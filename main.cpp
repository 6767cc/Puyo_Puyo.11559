#include<iostream>

using namespace std;

int i, j, xx, yy, pc, ans = 0;
char map[13][7];
bool ch[13][7];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int t = 0, p = 0, q = 0;

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
              if(map[l][r] == '.' || map[l+1][r] != '.') continue;
              else 
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
      if(ch[v][w]) 
      {
        map[v][w] = '.';
        ch[v][w] = false;
      }
    } 
  }
}

//뿌요가 걸리면 dfs로 갯수 찾으면서 ch배열에 같은 위치를 체크
void dfs(int a, int b, char color)
{
  ch[a][b] = true;
  
  for(int c = 0; c < 4; c++)
    {     
      xx = a + dx[c];
      yy = b + dy[c];

      if(xx < 0 || yy < 0 || xx >= 12 || yy >= 6) continue;
      if(map[xx][yy] != color || !ch[xx][yy]) continue;
      else
      {
        pc++;
        dfs(xx, yy, color);
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
    cout << ch[11][0] << endl;
    
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
            else continue;
          }
        }
      }
    
      if(NP) break; // 정상완료되면 종료
      fall();
      ans++;
  }
  
  cout << ans << endl << t << endl << p << endl << q << endl;
  
  cout << map[11][0] << ch[11][0] << map[10][2];
}