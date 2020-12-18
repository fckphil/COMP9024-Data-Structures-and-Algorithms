#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include <stdbool.h>
#include "PQueue.h"

#define VERY_HIGH_VALUE 99999
#define MAX_CHAR 32

/*
 Time Complexity: O(m^2 * k^2 + n)
 */
int find_index(char **, char*, int);  //find the index number of a station
int *dijkstraSSSP(Graph , Vertex, Vertex, int); //return the path from the destination to the source

int main() {
    int total_stop, n_schedules, n_stops;
    int i = 0, j = 0;
    printf("Enter the total number of stops on the network: ");
    scanf("%d", &total_stop);
    //input the name of stations into the array 'stop'
    char **stop = malloc(sizeof(char *) * total_stop);
    for (i = 0; i < total_stop; i++) {
        stop[i] = malloc(sizeof(char) * MAX_CHAR);
        scanf("%s", stop[i]);
    }

    Graph route_graph = newGraph(total_stop);
    printf("Enter the number of schedules: ");
    scanf("%d", &n_schedules);
    queue route = newQueue();
    for (i = 0; i < n_schedules; i++) {
        int schedule_no = i;
        printf("Enter the number of stops: ");
        scanf("%d", &n_stops);
        //save stations and respective time
        int *station = malloc(sizeof(int) * n_stops);
        int *time = malloc(sizeof(int) * n_stops);
        for (j = 0; j < n_stops; j++) {
            int hhmm;
            char stop_name[MAX_CHAR];
            scanf("%d", &hhmm); // hour + minute
            scanf("%s", stop_name);
            QueueEnqueue(route, hhmm, stop_name);
            station[j] = find_index(stop, stop_name, total_stop);
            time[j] = hhmm;
        }
        for (j = 0; j < n_stops - 1; j++) {
            int k = j + 1;
            Edge connection;
            connection.v = station[j];
            connection.w = station[k];
            connection.time1 = time[j];     //time of v
            connection.time2 = time[k];     //time of w
            //translate the time into minutes and then calculate the weight
            connection.weight = (time[k] / 100 * 60 + time[k] % 100) - (time[j] / 100 * 60 + time[j] % 100);
            connection.sched = schedule_no;
            connection.inthis = 1;
            insertEdge(route_graph, connection);
        }
        free(station);
        free(time);
    }

    char from[MAX_CHAR], to[MAX_CHAR];  //station name of the source and destination
    int depart_time;
    printf("\nFrom: ");
    while (scanf("%s", from) == 1 && strcmp(from, "done") != 0) { //if the input is not 'done'
        printf("To: ");
        scanf("%s", to);
        printf("Depart at: ");
        scanf("%d", &depart_time);
        printf("\n");
        int begin = find_index(stop, from, total_stop); //begin = the index of the source
        int end = find_index(stop, to, total_stop); // end = the index of the destination
        int *path = dijkstraSSSP(route_graph, begin, end, depart_time); //get the int array 'path'
        int k = 0;
        int iffind = 0; //iffind = 1 if find the path, iffind = 0 if there is no connection found

        for (i = 0; i < total_stop; i++) {
            if (path[i] == begin) {     //path founded
                k = i;  //k =  the index of the source in array 'path'
                iffind = 1;
                break;
            }
        }

        if (iffind == 1) {
            //use a variable 'flag' to indicate if #schedule is changed
            int flag = findEdge(matrix(route_graph), path[k], path[k - 1]).sched;
            for (i = k; i > 0; i--) {
                Edge e = findEdge(matrix(route_graph), path[i], path[i - 1]);
                if (e.sched != flag) {  //if the schedule is changed
                    printf("Change at %s\n", stop[e.v]);
                    printf("%04d %s\n", e.time1, stop[e.v]);
                    flag = e.sched;
                }
                if (e.v == begin) {
                    printf("%04d %s\n", e.time1, stop[e.v]);
                }
                printf("%04d %s\n", e.time2, stop[e.w]);
            }
        } else printf("No connection found.\n");
        printf("\nFrom: ");
    }
    //when the input is 'done'
    printf("Thank you for using goNSW.\n");
    free(route_graph);
    free(stop);
}

int find_index(char **arr, char *name, int num) {
    int index = 0;
    for (index = 0; index < num; index++) {
        if (strcmp(arr[index], name) == 0) break;
        else continue;
    }
    return index;
}


int *dijkstraSSSP(Graph g, Vertex source, Vertex des, int depart_time) {
    int nV = numOfVertices(g);
    int dist[nV];
    int pred[nV];
    bool vSet[nV];  // vSet[v] = true <=> v has not been processed
    int s;
    Edge e;
    int w;

    PQueueInit();
    for (s = 0; s < nV; s++) {
        joinPQueue(s);
        dist[s] = VERY_HIGH_VALUE;
        pred[s] = -1;
        vSet[s] = true;
    }
    dist[source] = 0;
    int i = 0;
    while (!PQueueIsEmpty()) {
        int cur = leavePQueue((dist));
        vSet[cur] = false;
        for (i = 0; i < nV; i++) {
            w = adjacent(g, cur, i);
            e = findEdge(matrix(g), cur, i);
            if (e.inthis == 0) continue;
            if (w && dist[cur] + w < dist[i] && vSet[i] == true) {
                if ((e.time1 / 100 * 60 + e.time1 % 100) - (depart_time / 100 * 60 + depart_time % 100) >= 0) {
                    // if the time is valid(no later than)
                    dist[i] = dist[cur] + w;
                    pred[i] = cur;
                    depart_time = e.time2;
                }
            }
        }
    }
    int *path;
    path = malloc(sizeof(int) * nV);
    for (i = 0; i < nV; i++) path[i] = -1;
    int index = des;
    path[0] = des;
    i = 1;
    while (pred[index] != -1) {
        path[i] = pred[index];
        index = pred[index];
        i++;
    }

    return path;
}
