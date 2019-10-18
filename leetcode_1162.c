/*************************************************************************
 > File Name: leetcode_1162.c
 > Author: qinchao
 > Mail: 1187620726@qq.com
 > Created Date:2019-10-18 Time:08:36:06.
 ************************************************************************/
typedef struct {
    int x;
    int y;
} item;

#define MAX_QUEUE (100 * 100)

item q[MAX_QUEUE];
int head;
int tail ;

void initQueue()
{
    head = tail = 0;
}

int getQueueSize()
{
    return (tail + MAX_QUEUE - head) % MAX_QUEUE;
}

int isQueueFull()
{
    int tmp = (tail + 1) % MAX_QUEUE;
    if (tmp == head) {
        return 1;
    }
    
    return 0;
}

int isQueueEmpty()
{
    if (head == tail) {
        return 1;
    }
    
    return 0;
}

// 添加到队列
void inQueue(int x, int y)
{
    if (isQueueFull()) {
        printf("err full\n");
        return;
    }
    
    q[tail].x = x;
    q[tail].y = y;
    
    tail = (tail + 1) % MAX_QUEUE;
    return;
}

void outQueue(int *x, int *y)
{
    if (isQueueEmpty()) {
        printf("err empty\n");
        return;
    }
    
    *x = q[head].x;
    *y = q[head].y;
    
    head = (head + 1) % MAX_QUEUE;
    return;
}

int maxDistance(int** grid, int gridSize, int* gridColSize){
   
    if (grid == NULL || gridSize < 1) {
        return -1;
    }
    
    initQueue();
    
    // 所有陆地添加到队列
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            if (grid[i][j] == 1) {
                inQueue(i, j);
            }
        }
    }
    
    // 判断全部为陆地或者全部为海洋
    int itemNum = getQueueSize();
    if (itemNum == 0|| itemNum == gridSize * (*gridColSize)) {
        return -1;
    }
    
    item walk[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int max = 0;
    while(!isQueueEmpty()) {
        // 从队列取元素
        int x, y;
        outQueue(&x, &y);
        for (int i = 0; i < 4; ++i) {
            int tx = x + walk[i].x;
            int ty = y + walk[i].y;
            
            // tx/ty合法
            if (tx >= 0 && tx < gridSize && ty >= 0 && ty < *gridColSize && grid[tx][ty] == 0) {
                grid[tx][ty] = grid[x][y] + 1;
                max = max > grid[tx][ty] ? max : grid[tx][ty];
                inQueue(tx, ty);
            }
        }
    }
    
    return max - 1;
}
