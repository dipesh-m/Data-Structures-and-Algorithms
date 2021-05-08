//USING SINGLE VECTOR
class BrowserHistory {
private:
    vector<string> v;
    int curr;
public:
    BrowserHistory(string homepage)
    {
        v.push_back(homepage);
        curr=0;
    }

    void visit(string url)
    {
        curr++;

        v.resize(curr);
        v.push_back(url);
    }

    string back(int steps)
    {
        curr=max(0, curr-steps);
        return v[curr];
    }

    string forward(int steps)
    {
        curr=min((int)v.size()-1, curr+steps);
        return v[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

//USING DOUBLY LL
class Node
{
public:
    string val;
    Node* prev;
    Node* next;

    Node(string str)
    {
        val=str;
        next=NULL;
        prev=NULL;
    }
};

class BrowserHistory {
private:
    Node* curr=NULL;
public:
    BrowserHistory(string homepage)
    {
        curr=new Node(homepage);
    }

    void visit(string url)
    {
        curr->next=new Node(url);
        curr->next->prev=curr;
        curr=curr->next;
    }

    string back(int steps)
    {
        while(steps>0 && curr->prev!=NULL)
        {
            curr=curr->prev;
            steps--;
        }

        return curr->val;
    }

    string forward(int steps)
    {
        while(steps>0 && curr->next!=NULL)
        {
            curr=curr->next;
            steps--;
        }

        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

//USING 2 STACKS
class BrowserHistory {
private:
    stack<string> s1,s2;
public:
    BrowserHistory(string homepage)
    {
        s1.push(homepage);
    }

    void visit(string url)
    {
        s1.push(url);
        while(!s2.empty())
            s2.pop();
    }

    string back(int steps)
    {
        while(steps>0 && s1.size()>1)
        {
            s2.push(s1.top());
            s1.pop();

            steps--;
        }

        return s1.top();
    }

    string forward(int steps)
    {
        while(steps>0 && !s2.empty())
        {
            s1.push(s2.top());
            s2.pop();

            steps--;
        }

        return s1.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
