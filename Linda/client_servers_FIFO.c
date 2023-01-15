void client(){
    int ticket;
    req_type request;
    rep_type reply;
    while(1){
        get(request);
        in("ticket", ?ticket);
        out("ticket", ticket+1);
        out("request",ticket, request);
        in("reply", ticket, ?reply);
        use(reply);
    }
}

void server(){
    int ticket, cnt=0;
    req_type request;
    rep_type reply;

    while(1){
        if(rdp("sum it")){
            out("sum", cnt);
            in("summed it");
        }
        else{
            in("next", ?ticket);
            out("next", ticket+1);
            in("request",ticket, ?request);
            reply=compute(request);
            out("reply", ticket, reply);
            cnt++;
        }
    }
}

int sumator(int N){

    out("sum it");

    int sum=0, cnt;
    for(int i=0;i<N;i++)
    {
        in("sum",?cnt);
        sum+=cnt;
    }
    in("sum it");

    for(int i=0;i<N;i++)
        out("summed it");

    return sum;
}

void init(){
    out("ticket", 0);
    out("next", 0);

    for(int i=0; i<Ns; i++)
        eval(server());

    for(int i=0; i<Nc; i++)
        eval(client());

    eval(sumator(Ns));
}