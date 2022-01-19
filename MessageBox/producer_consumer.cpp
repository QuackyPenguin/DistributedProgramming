msg box, p[NP], c[NC]; 

void producer(int id){

    msg m;
    int i;
    bool st;
    while(1){
        i=produce();
        m.item=i;
        m.id=id;
        m.op="prod";
        mbx_put(m, box);
        mbx_get(m, p[id], INF, st);
    }

}

void consumer(int id){
    msg m;
    bool st;
    int i;
    
    while(1){
        m.id=id;
        m.op="cons";
        mbx_put(m, box);
        mbx_get(m, c[id], INF, st);
        i=m.item;
        consume(i);
    }
}

void cordinator(){
    msg m;
    bool st;
    int head=0, tail=0, cnt=0;
    int buffer[N];
    Queue<msg>producers;
    Queue<msg>consumers;

    while(1){
        if(producers.size()>0&&cnt<N){
            m=producers.remove();
        }
        else if(consumers.size()>0&&cnt>0){
            m=consumers.remove();
        }
        else{
            mbx_get(m,box,INF,st);
        }

        switch(m.op){
            case "prod":
                if(cnt==N) waiting.put(m);
                else {
                    ++cnt;
                    buffer[head++]=m.item;
                    head%=N;
                    mbx_put(m, w[m.id]);
                }
            break;
            case "cons":
                if(cnt==0) waiting.put(m);
                else {
                    --cnt;
                    m.item=buffer[tail++];
                    tail%=N;
                    mbx_put(m, w[m.id]);
                }
            break;
            
        }
    }
}
