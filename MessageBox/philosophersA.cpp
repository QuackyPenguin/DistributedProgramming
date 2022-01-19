mbx p[N], fGet[N], fPut[N];

void philosopher(int id){
    int first;
    int second;
    msg m;
    bool st;

    if(id%2==0) {
        first=id;
        second=(id+1)%N;
    }
    else {
        first=(id+1)%N;
        second=id;
    }

    while(1){

        think();

        m.id=id;
        msg_put(m, fGet[first]);
        msg_get(m, p[id], INF, st);
        m.id=id;
        msg_put(m, fGet[second]);
        msg_get(m, p[id], INF, st);

        eat();

        msg_put(m, fPut[first]);
        msg_put(m, fPut[second]);
    }
}

void fork(int id){
    msg m;
    bool st;

    while(1){
        msg_get(m, fGet[id], INF, st);
        msg_put(m, p[m.id]);
        msg_get(m, fPut[id], INF, st);
    }
}
