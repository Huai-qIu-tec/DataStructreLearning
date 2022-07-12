#include <queue>
#include <stack>
#include <iostream>

using namespace std;

// 二叉树
typedef struct BiNode{
    char data;
    struct BiNode *lchild, *rchild;
}BiNode;

// 线索数
typedef struct ThreadNode{
    char data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;         // tag = 0时表示是子树, 1时表示是线索
}ThreadNode, *ThreadTree;

/*
    这里的线索树的数据结构表示成
    ----------------------------------------
    | ltag | *lchild | data | *rchild | rtag|
    ----------------------------------------
*/


BiNode* Creat()
{
    BiNode *bt;
    char ch;
    cin >> ch;
    if(ch == '#')   bt = nullptr;
    else
    {
        bt = (BiNode *)malloc(sizeof(BiNode));
        bt->data = ch;
        bt->lchild = Creat();
        bt->rchild = Creat();
    }
    return bt;
}

void visit(BiNode *bt)
{
    cout << bt->data << " ";
}

void PreOrder(BiNode *bt)
{
    if(bt == nullptr)
        return;
    else
	{
		visit(bt);
		PreOrder(bt->lchild);		//前序递归遍历bt的左子树
		PreOrder(bt->rchild);		//前序递归遍历bt的右子树
	}

}

void InOrder(BiNode *bt)
{
    if(bt == nullptr)
        return;
    else
	{
		InOrder(bt->lchild);
        visit(bt);		
		InOrder(bt->rchild);		
	}
}

void PostOrder(BiNode *bt)
{
    if(bt == nullptr)
        return;
    else
	{
		PostOrder(bt->lchild);	
		PostOrder(bt->rchild);
        visit(bt);		
	}
}

int TreeDepth(BiNode *bt)
{
    if(bt == nullptr)
        return 0;
    else
    {
        int ldepth = TreeDepth(bt->lchild);
        int rdepth = TreeDepth(bt->rchild);

        return ldepth > rdepth ? ldepth+1 : rdepth+1;
    }
}


void LevelOrder(BiNode *bt)
{
    queue<BiNode *> Q;
    BiNode *p = (BiNode *)malloc(sizeof(BiNode));
    Q.push(bt);
    while(!Q.empty())
    {
        p = Q.front();
        Q.pop();
        visit(p);
        if(p->lchild != nullptr)
            Q.push(p->lchild);
        if(p->rchild != nullptr)
            Q.push(p->rchild);
    }
}

/* 非递归实现三种遍历方式 */
// 非递归实现先序遍历
void PreOrder2(BiNode *T)
{
    stack<BiNode *> s;
    while(T || !s.empty())
    {
        if(T != nullptr)
        {
            cout << T->data << " ";
            s.push(T);
            T = T->lchild;
        }
        else
        {
            T = s.top();
            T = T->rchild;
            s.pop();
        }
    }
}

void InOrder2(BiNode *T)
{
    stack<BiNode *> s;
    while(T || !s.empty())
    {
        if(T != nullptr)
        {
            s.push(T);
            T = T->lchild;
        }
        else
        {
            T = s.top();
            cout << T->data << " ";
            T = T->rchild;
            s.pop();
        }
    }
}

void PostOrder2(BiNode *T)
{
    stack<BiNode *> s;
    BiNode *r = nullptr;
    while(T || !s.empty())
    {
        if(T != nullptr)
        {
            s.push(T);
            T = T->lchild;
        }
        else
        {
            T = s.top();
            if(T->rchild != nullptr && r != T->rchild)
            {
                T = T->rchild;
                s.push(T);
                T = T->lchild;
            }
            else
            {
                s.pop();
                cout << T->data << " ";
                r = T;
                T = nullptr;
            }
        }
    }

}


/* -------------- 线索树----------------------*/
ThreadNode *pre = nullptr;  // 全局变量

void visit_thread(ThreadNode *q)
{
    if(q->lchild == nullptr)        // 若左子树为空 则建立左线索树 前驱
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre != nullptr && q->rchild == nullptr)      // 若右子树为空 则建立右线索树 后继
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

// 中序线索化
void InThread(ThreadTree tree)
{
    if(tree != nullptr)
    {
        InThread(tree->lchild);
        visit_thread(tree);
        InThread(tree->rchild);
    }
}

void CreatInThread(ThreadTree tree)
{
    pre = nullptr;
    if(tree != nullptr)
    {
        InThread(tree);
        if(pre->rchild == nullptr)
            pre->rtag = 1;
    }
}

// 先序线索化
void PreThread(ThreadTree tree)
{
    if(tree->lchild == nullptr)        // 若左子树为空 则建立左线索树 前驱
    {
        tree->lchild = pre;
        tree->ltag = 1;
    }
    if(pre != nullptr && tree->rchild == nullptr)      // 若右子树为空 则建立右线索树 后继
    {
        pre->rchild = tree;
        pre->rtag = 1;
    }
    pre = tree;
    if(tree->ltag == 0)
        PreThread(tree->lchild);
    PreThread(tree->rchild);
    
}

void CreatPreThread(ThreadTree tree)
{
    pre = nullptr;
    if(tree != nullptr)
    {
        PreThread(tree);
        if(pre->rchild == nullptr)
            pre->rtag = 1;
    }
}

// 后序线索化
void PostThread(ThreadTree tree)
{
    if(tree != nullptr)
    {
        PostThread(tree->lchild);
        PostThread(tree->rchild);
        visit_thread(tree);
    }
}

void CreatPostThread(ThreadTree tree)
{
    pre = nullptr;
    if(tree != nullptr)
    {
        PostThread(tree);
        if(pre->rchild == nullptr)
            pre->rtag = 1;
    }
}




int main(void)
{
    system("chcp 65001");
    BiNode *root = (BiNode *)malloc(sizeof(BiNode));
    root = Creat();

    cout << "递归实现前序遍历:\t";        PreOrder(root);     cout << endl;
    
    cout << "非递归实现前序遍历:\t";      PreOrder2(root);    cout << endl;

    cout << "递归实现中序遍历:\t";        InOrder(root);      cout << endl;
    
    cout << "非递归实现中序遍历:\t";      InOrder2(root);     cout << endl;

    cout << "递归实现后序遍历:\t";        PostOrder(root);    cout << endl;

    cout << "非递归实现后序遍历:\t";      PostOrder2(root);   cout << endl;

    cout << TreeDepth(root) << endl;
    
    LevelOrder(root);   cout << endl;
    ThreadTree tree;
    //CreatInThread(tree);


    system("pause");
}