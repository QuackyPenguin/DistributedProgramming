mbx box, r[NR], w[NW];

void reader(int id)
{
    msg m;
    bool st;
    while(1){
        m.id=id;
        m.op="StartRead"
        mbx_put(m, box);
        mbx_get(m, r[id], INF, st);

        read();

        m.id=id;
        m.op="EndRead";
        mbx_put(m, box);
    }
}


void writer(int id)
{
    msg m;
    bool st;
    while(1){
        m.id=id;
        m.op="StartWrite"
        mbx_put(m, box);
        mbx_get(m, w[id], INF, st);

        write();

        m.id=id;
        m.op="EndWrite";
        mbx_put(m, box);
    }
}

void coordinator()
{
    msg m;
    Queue<msg> waiting;
    int cntR=0, cntW=0;
    bool waited=false;

    while(1){
        if(waiting.size()>0&&
            ((waiting.peek().op=="StartRead"&&cntW==0)||
            (waiting.peek().op=="StartWrite"&&cntW+cntR==0))){
            m=waiting.remove();
            waited=true;
        }
        else {
            mbx_get(m, box, INF, st);
            waited=false;
        }

        switch(m.op){
            case "StartRead":
                if((waiting.size()>0&&!waited)||cntW>0){
                    waiting.put(m);
                }
                else{
                    cntR++;
                    mbx_put(m, r[m.id]);
                }
            break;
            case "StartWrite":
                if((waiting.size()>0&&!waited)||cntW+cntR>0){
                    waiting.put(m);
                }
                else{
                    cntW++;
                    mbx_put(m, w[m.id]);
                }
            break;
            case "EndRead":
                cntR--;
            break;
            case "EndWrite":
                cntW--;
            break;

        }
    }
}
