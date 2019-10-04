typedef struct list{
    data_type *data;
    struct list *prev, *next;
}List, *List_p;

//init the head node
List_p InitHeadNode(void)
{
    List_p head = (List_p)calloc(1,sizeof(List));
    if(NULL == List)
    {
        printf("Init head node failed\n");
        return NULL;
    }
    //double loop linked list head node,the prev and the next point to head
    head->next = head;
    head->prev = head;
    
    return head;
}

//Create a new node
List_p CreatNewNode(data_type *data)
{
    if(NULL == data)
    {
        printf("creat new node failed:data error\n");
        return NULL;
    }
    
    List_p new = (List_p)calloc(1,sizeof(List_p));
    if(NULL == new)
    {
        printf("create new node failed:new node error\n");
        return NULL;
    }
    
    new->data = data;
    new->prev = new;
    new->next = new;
    
    return new;
}

//Search data
List_p Search(List_p head, data_type *data)
{
    if(NULL == head)
    {
        printf("search failed: head node error\n");
        return NULL;
    }
    
    List_p cur = head;
    while(cur->next != head)
    {
        cur = cur->next;
        if(!strcmp(cur->data, data))
        {
            return cur;
        }
        else 
            continue;
    }
    
    printf("data do not exist\n");
    return NULL;
}

//insert new node to the list
int Insert(List_p head, List_p new)
{
    if(NULL == head || NULL == new)
    {
        printf("head/new node error!\n");
        return -1;
    }
    else if(NULL != Search(head, new->data))
    {
        printf("new data have existed!\n");
        return -2;
    }
    
    List_p cur = head;
    while(cur->next != head)
    {
        cur = cur->next;
    }
    
    cur->next = new;
    new->next = head;
    new->prev = cur;
    head->prev = new;
    
    return 0;
}

//Delete data
int Delete(List_p head, data_type *data)
{
    if(NULL == head)
    {
        printf("head node error!\n");
        return -1;
    }
    
    List_p cur = Search(head, data);
    if(NULL == cur)
    {
        printf("data do not exist!\n");
        return -2;
    }
    
    cur->next->prev = cur->prev;
    cur->prev->next = cur->next;
    
    free(cur);
    cur = NULL;
    return 0
}

//Correct data
int Correct(List_p head, data_type *old, data_type *new)
{
    List_p cur = Search(head, old);
    if(NULL == cur)
    {
        printf("correct failed!\n");
        return -1;
    }
    
    strcpy(cur->data, new);
    
    return 0;
}

//destroy the list
int DestroyAll(List_p head)
{
    
}

//display data
void Display(List_p head)
{
    if(NULL == head)
    {
        printf("head node error!\n");
        return ;
    }
    
    List_p cur = head;
    while(cur->next != head)
    {
        cur = cur->next;
        printf("data format...",cur->data...);
    }
}
