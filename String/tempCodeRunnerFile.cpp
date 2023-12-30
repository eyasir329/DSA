for(int i=0;i<n;i++){
        int count = 1;
        int j=i;
        while(j<n-1){
            if(str[j+1]==str[i]&&str[i]!='1'){
                count++;
                str[j+1]='1';
            }
            j++;
        }
        if(str[i]!='1'){
            if(count>=1){
                t++;
            }
        }
    }