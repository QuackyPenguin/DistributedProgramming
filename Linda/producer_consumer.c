void producer(){
    int head, data;
    while(1){
        data=produce();
        in("head",?head);
        out("head", head+1);
        out("data", data, head);
    }
}

void consumer(){
    while(1){
        in("tail", ?tail);
        out("tail", tail+1);
        in("data", data, tail);
        consume(data);
    }
}

void init(){
    out("head",0);
    out("tail",0);
    for(int i=0;i<Np;i++)
        eval(producer());
    for(int i=0;i<Nc;i++)
        eval(consumer());
}