class Subvector
{
public:
    Subvector()
    {
        mas= new int[capasity];
    }
    ~Subvector(){};

    void resize(unsigned int new_capasity)
    {
        masnew= new int[capasity];
        for(int i=0; i<=top; i++)
        {
            *(this->masnew+i)=*(this->mas+i);
        }
        delete [] mas;
        capasity+=new_capasity;
        mas= new int[capasity];
        for(int i=0; i<=top; i++)
        {
            *(this->mas+i)=*(this->masnew+i);
        }
        delete [] masnew;
    }

    void push_back(int d)
    {
        if(top<capasity-1)
        {
            top++;
            *(this->mas+top+1)=d;
        }
        else
        {
            resize(3);
            top++;
            *(this->mas+top+1)=d;
        }
    }

    void pop_back()
    {
        if(top>0) top--;
    }

    void shrink_to_fit()
    {
        masnew=new int[top];
        for(int i=0; i<=top; i++)
        {
            *(this->masnew+i)=*(this->mas+i);
        }
        delete [] mas;
        capasity=top;
        mas= new int[capasity];
        for(int i=0; i<=top; i++)
        {
            *(this->mas+i)=*(this->masnew+i);
        }
        delete [] masnew;

    }

    void clear()
    {
        top=0;
    }

private:
    int *mas;
    int *masnew;
    unsigned int top=0;
    unsigned int capasity=3;
};
