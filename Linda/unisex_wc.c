void man(){
    int dir, numm;

    while(1){
        in("direction", ?dir);
        if(dir==1){
            out("direction", 1);
            rd("numw", 0);
        }
        out("direction", 2);
        in("numm", ?numm);
        out("numm", numm+1);

        in("cabine");
        relieve();
        out("cabine");

        in("numm", ?numm);
        out("numm", numm-1);
}

void init(){
    out("direction", 1);
    out("numm", 0);
    out("numw", 0);
    
    for(int i=0;i<N;i++)
        out("cabine");
    for(int i=0;i<Nw;i++)
        eval(woman());
    for(int i=0;i<Nm;i++)
        eval(man());
}