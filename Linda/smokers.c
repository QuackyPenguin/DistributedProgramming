void agent(){
    int x;
    while(1){
        x=(int)((rand()*3)/RAND_MAX);
        switch(x){
            case 0:
                out("Tobacco");
                out("Match");
                break;
            case 1:
                out("Tobacco");
                out("Paper");
                break;
            case 2:
                out("Match");
                out("Paper");
                break;
        }
        out("Watch");
        in("Ok");
    }
}

void smoker_with_match(){
    while(1){
        in("Watch")
        if(rdp("Paper")&&rdp("Tobacco")){
            in("Paper");
            in("Tobacco");
            enjoy();

            int n;
            in("waiting", ?n);
            for(int i=0;i<n;i++)
                out("wait");
            for(int i=0;i<n;i++)
                in("done");
            
            out("waiting",0);
            out("Ok");
        }
        else{
            int n;
            in("waiting", ?n);
            out("waiting", n+1);

            out("Watch");
            in("wait");

            out("done");
        }
    }
}

void init(){
    out("wait",0);
    eval(agent());
    for(int i;i<N;i++){
        eval(smoker_with_match());
        eval(smoker_with_tobacco());
        eval(smoker_with_paper());
    }
}