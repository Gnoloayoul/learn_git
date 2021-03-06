struct node{
    int key;
    int val;
    struct node *next;
};
struct table{
    int size;
    struct node **list;
};
struct table *createTable(int size){
    struct table *t = (struct table*)malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct node**)malloc(sizeof(struct node*)*size);
    int i;
    for(i=0;i<size;i++)
        t->list[i] = NULL;
    return t;
}
int hashCode(struct table *t,int key){
    if(key<0)
        return -(key%t->size);
    return key%t->size;
}
void insert(struct table *t,int key){
    int pos = hashCode(t,key);
    struct node *list = t->list[pos];
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = list;
    
    while(temp){
        if(temp->key==key){
            temp->val++;
            return;
        }
        temp = temp->next;
    }

    newNode->key = key;
    newNode->val = 1;
    newNode->next = list;
    t->list[pos] = newNode;
}

int lookup(struct table *t,int key){
    int pos = hashCode(t,key);
    struct node *list = t->list[pos];
    struct node *temp = list;
    while(temp){
        if(temp->key==key){
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}


int subarraySum(int* nums, int numsSize, int k){

    struct table *t = createTable(1000);
    int sum=0,count=0,n;
 
    insert(t,0);
    for(int i=0;i<numsSize;i++)
    {
        sum+=nums[i];

        if((n=lookup(t,sum-k))!=-1)
        {
            count+=n;
        }
        insert(t,sum);
    }
    
    return count;
}