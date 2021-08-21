struct Node{
    int locX;
    int locY;
    struct Node* next;
    struct Node* previous;
};

typedef struct{
    struct Node* head;
    struct Node* tail;
    int size;
    int count; 
}myQueueForBfs;

myQueueForBfs* queueCreateAndInite(int size){
    myQueueForBfs* res = (myQueueForBfs*)malloc(sizeof(myQueueForBfs));
    res->head = NULL;
    res->tail = NULL;
    res->size = size;
    res->count = 0;
    return res;
}

int queueInsert(myQueueForBfs* obj, int locX, int locY){
    if(obj->size == obj->count){
        return 0;
    }
    
    struct Node* nodeNew = (struct Node*)malloc(sizeof(struct Node));
    nodeNew->next = NULL;
    nodeNew->previous = NULL;
    nodeNew->locX = locX;
    nodeNew->locY = locY;
    if(obj->count == 0){
        obj->head = nodeNew;
        obj->tail = nodeNew;
    }else{
        obj->head->previous = nodeNew;
        nodeNew->next = obj->head;
        obj->head = nodeNew;
    }
    obj->count++;
    return 1;
}

int queueDelete(myQueueForBfs* obj){
    if(obj->count == 0){
        return 0;
    }
    struct Node* nodeOld;// = (struct Node*)malloc(sizeof(struct Node));
    nodeOld = obj->tail;
    obj->tail = obj->tail->previous;
    if(obj->tail){
        obj->tail->next = NULL;
    }
    obj->count--;
    free(nodeOld);
    return 1;    
}

int queueGettail(int* locX, int* locY, myQueueForBfs* obj){
    if(obj->count == 0){
        return 0;
    }

    *locX = obj->tail->locX;
    *locY = obj->tail->locY; 
    return 1;
}

int quequeFree(myQueueForBfs* obj){
    if(obj->count == 0){
        free(obj);
        return 1;
    }

    struct Node* node = obj->head;
    struct Node* next;

    while(node){
        next = node->next;
        free(node);
        node = next;
    }

    free(obj);
    return 1;
}

int boundCheck(int x,int y, int m,int n){
    if(x>=0 && x< m && y>=0 && y<n){
        return 1;
    }else{
        return 0;
    }
    
}

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
    int i = 0;
    int k = 0;
    int m = 0;
    int n = 0;
    int routeLen = 0;
    int nodeNum = 0;
    int locX = 0;
    int locY = 0;

    if(grid[gridSize-1][gridSize-1] != 0 || grid[0][0] != 0){
        return -1;
    }

    if(gridSize == 1 & grid[0][0] == 0){
        return 1;
    }

    //int** visited = (int**)malloc(sizeof(int*)*gridSize);


    myQueueForBfs* queue;
    queue = queueCreateAndInite(gridSize*gridSize);
    queueInsert(queue,0,0);
    grid[0][0]=1;
    routeLen = 1;
    while(queue->count!=0){
        nodeNum = queue->count;
        for(i=0;i<nodeNum;i++){
            queueGettail(&locX,&locY,queue);
           // printf("%d %d",locX,locY);
            queueDelete(queue); 
            //printf("%d\n",queue->count);
            for(k=0;k<8;k++){
                if(k==0){m=0;n=1;}
                if(k==1){m=0;n=-1;}
                if(k==2){m=1;n=0;}
                if(k==3){m=-1;n=0;}
                if(k==4){m=1;n=1;}
                if(k==5){m=-1;n=-1;}
                if(k==6){m=1;n=-1;}
                if(k==7){m=-1;n=1;}
                if(boundCheck(locX+m,locY+n,gridSize,gridColSize[0])){
                    if((locX+m)==gridSize-1 && (locY+n)==gridSize-1){
                        return routeLen + 1;
                    }
                    if(grid[locX+m][locY+n]==0){
                        queueInsert(queue,locX+m,locY+n);    
                        grid[locX+m][locY+n]=1;
                        //printf("%d\n",queue->count);
                    }
                }
            } //8¸ö·½Ïò
        }
        //printf("\n");
        routeLen++; 
    }

    quequeFree(queue);
    return -1;
}
