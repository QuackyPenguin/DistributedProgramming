void player(int id){
    int toss, toss1, toss2;
    int iteration=0, end=0, winner;

    while(!end){
        toss=(int)(rand()*2/RAND_MAX);

        out("toss", id, iteration, toss);
        out("toss", id, iteration, toss);
        in("toss", (id+1)%3, iteration, ?toss1);
        in("toss", (id+2)%3, iteration, ?toss2);

        end=!((toss==toss1)&&(toss==toss2)&&(toss1==toss2));
        winner=(toss!=toss1)&&(toss!=toss2);
        
        iteration++;
    }
    if(winner) play(id);
}

void init(){
    eval(player(0));
    eval(player(1));
    eval(player(2));
}