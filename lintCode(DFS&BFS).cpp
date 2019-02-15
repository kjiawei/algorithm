//DFS
char mark[5][5];　　//用于记录走过的点
int min = 26;　　　　//能抵达终点的最短步数
int ways = 0;　　　　//走法数
int dir[4][2] = {　　//右下左上四个方向
    { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 }
};

void dfs(int step, int x, int y)
{
    int i;
    int tx, ty;
    if (x == 4 && y == 4) {
        if (step < min)
            min = step;
        ways++;
        return;
    }
    for (i = 0; i < 4; i++) {
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if (tx < 0 || tx>4 || ty < 0 || ty>4)
            continue;
        if (map[ty][tx] == 0 && mark[ty][tx] == 0) {
            mark[ty][tx] = 1;　　　　//标记已到过此点
            dfs(step + 1, tx, ty);　　//进行下一步尝试
            mark[ty][tx] = 0;　　//尝试结束，取消对此点标记
        }
    }
}

//BFS
typedef struct{
    int x;
    int y;
    int step;
}pt;

pt queue[25];
int front = 0, rear = 0;
void bfs(void)
{
    int i;
    int tx, ty;
    int flag = 0;　　//flag判断是否找到终点
    queue[rear].x = 0;　　//将出发点入队
    queue[rear].y = 0;
    queue[rear].step = 0;
    rear++;
    while (front < rear) {　　//队列中还有元素的话
        for (i = 0; i < 4; i++) {　　//遍历四个方向
            tx = queue[front].x + dir[i][0];
            ty = queue[front].y + dir[i][1];
            if (tx < 0 || tx>4 || ty < 0 || ty>4)
                continue;
            if (map[ty][tx] == 0 && mark[ty][tx] == 0) {
                mark[ty][tx] = 1;
                queue[rear].x = tx;
                queue[rear].y = ty;
                queue[rear].step = queue[front].step + 1;
                rear++;
            }
            if (tx == 4 && ty == 4) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
        front++;
    }
    printf("%d\n", queue[rear - 1].step);
}

//2.给出若干闭合区间，合并所有重叠的部分
/*
Definition of Interval:
class Interval{
    int start,end;
    Interval(int start,int end){
        this->start = start;
        this->end = end;
    }
};
*/

class Solution{
public:  
    static bool cmp(const Interval &a,const Interval &b){
        return a.start < b.start;
    }
    /*
    @param intervals:interval list.
    @return A new interval list.
    */
    vector<Interval> merge(vector<Interval> &intervals){
        int size = intervals.size();
        if(size <= 0){
            return vector<Interval>();
        }

        vector<Interval> result;
        sort(intervals.begin(),intervals.end(),cmp);
        result.push_back(intervals[0]);
        for(int i = 1;i<size;i++){
            if(result.back().end >= intervals[i].start){
                result.back().end = (result.back().end > intervals[i].end)?result.back().end:intervals[i].end;
            }else{
                result.push_back(intervals[i]);
            }
            return result;
        }
    }
};