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
    int ticket=0;
    req_type request;
    rep_type reply;
    while(1){
        in("request",ticket, ?request);
        reply=compute(request);
        out("reply", ticket, reply);
        ticket++;
    }
}

void init(){
    out("ticket", 0);
    eval(server());
    for(int i=0;i<Nc;i++)
        eval(client());
}