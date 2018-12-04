// code for scheduling ********************************************
#include <bits/stdc++.h>
#include <stdio.h>
#include <limits.h>
using namespace std;

#define V 9


int minDistance(int dist[], bool sptSet[])
{

   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;


   return min_index;
}


int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("   %d                %d\n", i, dist[i]);
}



void dijkstra(int graph[V][V], int src)
{
    std::vector< pair < int,pair<int,int> > > m;
     int dist[V];
     int g[V][V]={0};
     bool sptSet[V];


     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;


     dist[src] = 0;
     int last,l=0;
     last = dist[src];
    // cout<<"below table is showing the selecting path of the nodes"<<endl;
    //  cout<< "from(dept. pt.)          to(arrival pt.)"<<endl;
     for (int count = 0; count < V-1; count++)
     {

       int u = minDistance(dist, sptSet);
       sptSet[u] = true;

       for (int v = 0; v < V; v++)


         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v]){
            dist[v] = dist[u] + graph[u][v];
            //cout<<"      "<<u<<"                    "<<v<<endl;
            /*here wwe are storing the pair of boarding point and arrival point as index and value as total distance from the source*/
            g[v][u] = dist[v];
          }

     }


     printSolution(dist, V);


     for(int i=1; i<V; i++){
       last = 0;
       for(int j=1; j<V; j++){
          if(g[i][j]!=0 && g[i][j]<g[i][last]){
            g[i][last] = 0;
            last = j;

          }
          else if (g[i][j]!=0 && g[i][j]>=g[i][last] && g[i][last]!=0){
            g[i][j] = 0;
          }
          else if(g[i][j]!=0){
            last = j;
          }
       }
     }

     for(int i=0; i<V; i++){
       last = 0;
       for(int j=0; j<V; j++){
          if(g[i][j]) {m.push_back(make_pair(dist[j],make_pair(j,i)));}
       }
       //cout<<endl;
     }
     sort(m.begin(),m.end());
     cout<<"From (boarding)     To(destination)     departure time      arrival time"<<endl;
     int hr = 8;
     int min = 0;
     int add_hr_arrival,add_hr_boarding,add_min_arrival,add_min_boarding;
     int temp_time_boarding,temp_time_arrival;
     for(int i=0;i<m.size();i++)
     {
       temp_time_boarding = (m[i].first)*10;
       temp_time_arrival = (dist[m[i].second.second])*10;
       add_min_boarding = temp_time_boarding%60;
       add_hr_boarding = temp_time_boarding/60;
       add_min_arrival  = temp_time_arrival%60;
       add_hr_arrival  = temp_time_arrival/60;

       if(add_min_arrival==0 && add_min_boarding==0){
         if(hr+add_hr_arrival>9){
            cout<<m[i].second.first<<"                      "<<m[i].second.second<<"                    "<<hr+add_hr_boarding<<":"<<min+add_min_boarding<<"0"<<"                 "<<hr+add_hr_arrival<<":"<<min+add_min_arrival<<"0"<<endl;
         }
         else{
            cout<<m[i].second.first<<"                      "<<m[i].second.second<<"                    "<<hr+add_hr_boarding<<":"<<min+add_min_boarding<<"0"<<"                  "<<hr+add_hr_arrival<<":"<<min+add_min_arrival<<"0"<<endl;
         }

       }
       else if(add_min_arrival==0 && add_min_boarding!=0){
         if(hr+add_hr_arrival>9){
            cout<<m[i].second.first<<"                      "<<m[i].second.second<<"                  "<<hr+add_hr_boarding<<":"<<min+add_min_boarding<<"                   "<<hr+add_hr_arrival<<":"<<min+add_min_arrival<<"0"<<endl;
         }
         else{
            cout<<m[i].second.first<<"                      "<<m[i].second.second<<"                  "<<hr+add_hr_boarding<<":"<<min+add_min_boarding<<"                    "<<hr+add_hr_arrival<<":"<<min+add_min_arrival<<"0"<<endl;
         }

       }
       else if(add_min_arrival!=0 && add_min_boarding==0){
         if(hr+add_hr_arrival>9){
            cout<<m[i].second.first<<"                      "<<m[i].second.second<<"                  "<<hr+add_hr_boarding<<":"<<min+add_min_boarding<<"0"<<"                   "<<hr+add_hr_arrival<<":"<<min+add_min_arrival<<endl;
         }
         else{
            cout<<m[i].second.first<<"                      "<<m[i].second.second<<"                  "<<hr+add_hr_boarding<<":"<<min+add_min_boarding<<"0"<<"                    "<<hr+add_hr_arrival<<":"<<min+add_min_arrival<<endl;
         }

       }
       else if(add_min_arrival!=0 && add_min_boarding!=0){
         if(hr+add_hr_arrival>9){
           cout<<m[i].second.first<<"                      "<<m[i].second.second<<"                  "<<hr+add_hr_boarding<<":"<<min+add_min_boarding<<"                   "<<hr+add_hr_arrival<<":"<<min+add_min_arrival<<endl;
         }
         else{
           cout<<m[i].second.first<<"                      "<<m[i].second.second<<"                  "<<hr+add_hr_boarding<<":"<<min+add_min_boarding<<"                    "<<hr+add_hr_arrival<<":"<<min+add_min_arrival<<endl;
         }

       }
       //cout<<m[i].second.first<<"                      "<<m[i].second.second<<"                    "<<m[i].first<<"                    "<<dist[m[i].second.second]<<endl;
       //cout<<m[i].second.first<<"                      "<<m[i].second.second<<"                    "<<hr+add_hr_boarding<<":"<<min+add_min_boarding<<"                    "<<hr+add_hr_arrival<<":"<<min+add_min_arrival<<endl;
     }
}


int main()
{
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
//**************************************************************************



