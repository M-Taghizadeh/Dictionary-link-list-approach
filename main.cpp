#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

struct dictionary//my list
{
    dictionary *link;
    string word;
    string definition;

}*head=NULL;


void add_word();
void delete_word();
void search_word();
void show_dictionary();
int exit();

int main()
{
    int ch;
    //menu
    cout<<setw(10)<<"MENU\n\n";
    while(ch)
    {
        system("color 3");
        cout<<"1.ADD WORD\n\n";
        cout<<"2.DELETE WORD\n\n";
        cout<<"3.SEARCH WORD\n\n";
        cout<<"4.SHOW DICTIONARY\n\n";
        cout<<"5.EXIT\n\n";
        cout<<"Choice option : ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            {
                system("cls");
                add_word();
                break;
            }
        case 2:
            {
                system("cls");
                delete_word();
                break;
            }
        case 3:
            {
                system("cls");
                search_word();
                break;
            }
        case 4:
            {
                system("cls");
                show_dictionary();
                break;
            }
        case 5:
            {
                system("cls");
                ch=exit();
                getch();
            }
        default:
            {
                system("cls");
                break;
            }
        }

    }

    return 0;
}

void add_word()
{
    system("color 2");
    dictionary *p;
    dictionary *q;
    dictionary *temp;
    q=head;
    p=new dictionary;
    cout<<"Enter Word : ";
    cin>>p->word;
    cout<<"Enter definition : ";
    cin>>p->definition;

    if(q==NULL)//if list is empty:create list
    {
        p->link=NULL;
        head=p;
    }
    else
    {
        p->link=NULL;
        if(p->word<=q->word)//insert to first
        {
            if(head==NULL)//if list is was empty:create list
            {
                head=p;
            }
            else
            {
                p->link=head;//insert to first
                head=p;
            }
        }
        else//درج در وسط
        {
            while(q->link!=NULL)
            {
                temp=q;
                q=q->link;
                if(p->word<=q->word)
                    break;
            }
            if(q->link==NULL)//insert to end of list
            {
                while(q->link!=NULL)
                {
                    q=q->link;
                }
                q->link=p;
            }
            else//درح در وسط
            {
                p->link=q;
                temp->link=p;
            }
        }
    }
getch();
system("cls");
}

void delete_word()
{
    system("color 4");

    dictionary *q;
    dictionary *temp;
    int found=0;
    q=head;
    if(q==NULL)
    {
        cout<<"list is empty!";
    }
    else
    {
        string key;
        cout<<"Enter word : ";
        cin>>key;

        if(q->word==key)
        {
            temp=head;
            head=head->link;
            cout<<temp->word<<" has been delete.";
            delete q;
        }
        else
        {
            while(q->link!=NULL)
            {
                temp=q;
                q=q->link;
                if(q->word==key)
                {
                    found=1;
                    break;
                }
            }
            if(found==0)
            {
                cout<<"WORD not found!";
            }
            else
            {
                if(q->link==NULL)
                {
                    temp->link=NULL;
                    cout<<temp->word<<" has been delete.";
                    delete q;

                }
                else
                {
                    temp->link=q->link;
                    cout<<temp->word<<" has been delete.";
                    delete q;
                }
            }

        }
    }

    getch();
    system("cls");
}

void search_word()
{
    system("color F");
    dictionary *p;
    p=head;
    string key;
    if(p==NULL)
    {
        cout<<"list is empty!";
    }
    else
    {
        cout<<"Enter WORD : ";
        cin>>key;

        while(p->link==NULL)
        {
            if(p->word==key)
            {
                break;
            }
            p=p->link;
        }

        if(p->word==key)
        {
            cout<<"WORD : ";
            cout<<p->word<<endl;
            cout<<"DEFINITION : "<<p->definition<<endl;

        }
        else
            cout<<"word not found!";
    }

getch();
system("cls");
}

void show_dictionary()
{
    system("color F");
    dictionary *p;
    dictionary *temp;

    temp=head;

    cout<<"[DICTIONARY]\n\n";
    if(head==NULL)
    {
        cout<<"list is empty!";
    }

    else
    {
        for(int i=1;temp!=NULL;i++)
        {
            cout<<"---------------------------------"<<endl;
            cout<<"WORD "<<i<<" : ";
            cout<<temp->word<<endl;
            cout<<"DEFINITION : "<<temp->definition<<endl;
            cout<<"---------------------------------"<<endl;
            temp=temp->link;

        }
    }

    getch();
    system("cls");

}

int exit()
{
    system("color 17");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tproduct by mohammad taghizadeh\n";
    return false;
}
