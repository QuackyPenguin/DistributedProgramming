void philosophers1(int i, int N){
    int left=i, right=(i+1)%N;
    while(1){
        think();
        in("entry");
        in("fork", right);
        in("fork", left);
        eat();
        out("fork",right);
        out("fork",left);
        out("entry");
    }
}

void init(){
    for(int i=0;i<N;i++){
        out("fork",i);
        eval(philosophers1(i,N))
        if(i!=N-1) out("entry";)
    }
}

---------2----------

void philosophers2(int i, int N){
    int left=(i+i%2)%N, right=(i+(i+1)%2)%N;
    while(1){
        think();
        in("fork", right);
        in("fork", left);
        eat();
        out("fork",right);
        out("fork",left);
    }
}