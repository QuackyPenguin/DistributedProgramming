void reader(){
    int nr, ticket;
    while(1){
        in("ticket", ?ticket);
        out("ticket", ticket+1);

        in("room", ticket);
        in("readers", ?nr);
        out("readers", nr+1);
        out("room", ticket+1);

        read();

        in("readers",?nr);
        out("readers", nr-1);
    }
}

void writer(){
    int ticket;
    while(1){
        in("ticket", ?ticket);
        out("ticket", ticket+1);

        in("room", ticket);
        rd("readers", 0);

        write();

        out("room". ticket+1);
    }
}

void init(){
    out("readers",0);
    out("room", 0);
    out("ticket", 0);           

    for(int i=0;i<Nw;i++){
        eval(writer());
    }
    for(int i=0;i<Nr;i++){
        eval(reader());
    }
}