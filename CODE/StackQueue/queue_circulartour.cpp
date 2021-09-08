struct petrolPump
{
    int petrol;
    int distance;
};

int circularTour(petrolPump p[],int n){
    int count=0;
    int start=0;
    for(int i=0;i<n;i++){
        count++;
        if(p[i].petrol>=p[i].distance){
            start=i;
            break;
        }
    }
    int petrol_atReaching_next =p[start].petrol-p[start].distance;
    int reached=(start+1)%n;

    while(count<=2*n){
        if(start==reached)return start;

        petrol_atReaching_next+=p[reached].petrol-p[reached].distance;
        reached=(reached+1)%n;
        count++;
        if(petrol_atReaching_next<0){
            for(int j=reached;j<n;j++){
                count++;
                if(p[j].petrol>=p[j].distance){
                    start=j;
                    petrol_atReaching_next =p[j].petrol-p[j].distance;
                    reached=(start+1)%n;
                    break;
                }
            }
        }
    }

    return -1;
}
