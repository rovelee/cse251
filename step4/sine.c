#include<stdio.h>
#include<math.h>

//打印sin直角坐标系的图像，*代表点
void draw(double x, int n){
    int a = (int)(x*10) + n/2;
    printf("|");
    for(int i=0;i<a;i++)
        printf(" ");
    printf("*\n");
}
//从终端接收steps的值，如果输入小于2则返回1，再次询问赋值
int ask_for_input(int* s){
    printf("Input the number of steps: ");
    scanf("%d",s);
    if(*s<2) return 1;
    else return 0; //返回0，终止循环
}
//使用波浪线来绘图, 绘图的点在增区间时为'\'，减区间时为’/'，90°和180°时则为 *
void w_draw(double angle, int maxSize){
    // 保证angle在0~2PI之间
    if(angle>M_PI*2) angle -= M_PI*2;
    if(angle<0) angle += M_PI*2;
    // 计算sine值
    double sinVal = sin(angle);
    // 设置输出字符
    char c = (angle==M_PI/2 || angle==3*M_PI/2)?'*':((angle<M_PI/2 || angle > 3*M_PI/2)?'\\':'/');
    // 确定字符前输出的空格数
    int a = (int)((sinVal*(maxSize/2)+maxSize/2));
    for(int i=0; i<a; i++) printf(" ");
    printf("%c\n", c );
}

int main(){
    double angle;
    double maxAngle = M_PI * 2;
    int steps, status;
    status = 1;
    while(status){
        status = ask_for_input(&steps);
    }
    int i ;
    int max_size = 20;
    double sinVal;
    for(i = 0; i<=steps; i++){
        angle = (double) i / (double) steps * maxAngle;
        // sinVal = sin(angle);
        // printf("%3d: %5.2f %6.3f", i, angle, sinVal);
        // draw(sinVal,draw_size);
        printf("%3d: %5.2f ", i, angle );
        w_draw(angle, max_size); 
    }
    return 0;
}