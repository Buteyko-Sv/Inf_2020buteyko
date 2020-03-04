struct sflist
{
    int data;
    sflist * next;
};

class subforwardlist
{
public:
    subforwardlist()
    {
        head=0;
    }
    ~subforwardlist();
    void push_forward(int x) //Функция добавления элементов в начало списка
    {
        sflist *temp = new sflist;
        temp->data = x;
        temp->next = head;
        head = temp;
    }

    void pop_forward()

    {
        sflist* temp=head;
        head=head->next;
        delete temp;
    }

    void push_back(int x)
    {
        sflist *temp= new sflist;
        temp->data=x;
        temp->next=0;
    }

    void pop_back()
    {
        sflist *temp=head;
        while(temp)
        {
            temp=temp->next;
        }
        sflist *d=temp;
        delete temp;
        d=0;
    }

    unsigned int size()
    {
        unsigned int i=0;
        sflist *temp=head;
        while(temp)
        {
            temp=temp->next;
            i++;
        }
        return i;
    }

    void clear()
    {
        sflist *del=head->next;

        sflist *t;
        while(del)
        {
            t = del;
            del = del->next;
            delete t;
        }
        head->next = 0;
    }

private:
    sflist *head;
};
