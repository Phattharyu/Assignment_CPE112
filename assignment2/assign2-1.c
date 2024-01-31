//66070503448, Phattharapong Duangkham
#include<stdio.h>
#include<math.h>

struct student
{
    char name[20];
    double score;
};

int main() {
    int n;
    scanf("%d",&n);
    struct student a[n];
    for(int i=0;i<n;i++) {
        scanf("%s",a[i].name);
        scanf("%lf",&a[i].score);
    }
    double sum=0;
    for(int i=0;i<n;i++ ) {
        sum+=a[i].score;
    }
    double mean = sum/n;
    double sd,t=0.0;
    for(int i=0;i<n;i++) {
        t+=pow((a[i].score-mean),2);
    }
    sd = sqrt(t/(n));
    double max=a[0].score,min=a[0].score;
    int pos1=0,pos2=0;
    for(int i=1;i<n;i++) {
        if(a[i].score>max) {
            max = a[i].score;
            pos1 = i;
        }
        if(a[i].score<min) {
            min = a[i].score;
            pos2=i;
        }
    }
    //printing the result
    printf("%.2lf %.2lf %s %s\n",mean,sd,a[pos1].name,a[pos2].name);
}