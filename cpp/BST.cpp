#include <iostream>


typedef struct BSTNode{
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BiTree;


bool BST_Insert(BiTree &T, int k)
{
    if(T == nullptr)
    {
        T = (BSTNode *)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = nullptr;
        return true;
    }
    else if(T->key == k)
        return false;
    else if(T->key < k)
        return BST_Insert(T->rchild, k);
    else
        return BST_Insert(T->lchild, k);
}

BSTNode *BST_Search(BiTree T, int k)
{
    while(T != nullptr && T->key != k)
    {
        if(T->key > k)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}

void Creat_BST(BiTree &T, int str[], int n)
{
    T = nullptr;
    int i = 0;
    while(i < n)
    {
        BST_Insert(T, str[i]);
        i++;
    }
}

BSTNode* BST_Delete(BiTree &T, int k)
{
    BSTNode *p; //指向当前节点
    BSTNode *q; //指向p的下一个节点
    if(T == nullptr || T->key == k && T->lchild == nullptr && T->rchild == nullptr)
        return nullptr;
    else
    {
        // 定位删除操作
        if(T->key == k)
        {
            // 1. 当删除节点为叶子节点时
            if(T->lchild == nullptr && T->rchild == nullptr)
                delete T;
            
            // 2.只有左子树或者右子树
            // 此时递归调用的参数为 BST_Delete(T->rchild, k), 因此返回时就会把T赋值给T->rchild, 也就连接起来了
            else if(T->lchild ==nullptr && T->rchild != nullptr)
            {
                p = T;
                T = T->rchild;
                delete p;
            }
            // 此时递归调用的参数为 BST_Delete(T->lchild, k), 因此返回时就会把T赋值给T->lchild, 也就连接起来了
            else if(T->lchild != nullptr && T->rchild == nullptr)
            {
                p = T;
                T = T->lchild;
                delete p;
            }

            // 3.左右子树均有
            else
            {
                // 用后继的最小节点来代替当前节点
                p = T;
                q = T->rchild;
                while(q->lchild)
                {
                    p = q;
                    q = q->lchild;
                }
                T->key = q->key;
                if(p != T)
                    p->lchild = q->rchild;
                else
                    p->rchild = q->rchild;
                delete q;

                // 用前驱的最大节点来代替当前节点

                // 我们首先按伪装成前驱结点来写代码，找到当前结点root的左结点的最右边的结点
                // p指向当前结点，q指向当前结点的左结点
                // p = T;
                // q = T->lchild;
                // // 假设q有右子树就不断往右推进，p随之跟进，而假设q没有右子树，p和q都滞留在原地
                // while(q->rchild)
                // {
                //     p = q;
                //     q = q->rchild;
                // }
                // T->key = q->key;
                // if(p != T)
                //     p->rchild = q->lchild;
                // else
                //     p->lchild = q->lchild;
                // delete q;

            }
        }
        else if(T->key < k)
            return BST_Delete(T->rchild, k);
        else
            return BST_Delete(T->lchild, k);
        
        return T;
    }
}

void visit(BSTNode *bt)
{
    std::cout << bt->key << " ";
}

void InOrder(BSTNode *bt)
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



int main(void)
{
    //int str[12] = {3, 2, 5, 1, 4, 6, 11, 9, 8, 10, 7, 12};
    int str[11] = {3, 2, 5, 1, 4, 6, 11, 9, 10,  12, 8};
    BiTree T;
    Creat_BST(T, str, 11);
    InOrder(T);
    BST_Delete(T, 2);
    std::cout << std::endl;
    InOrder(T);
    system("pause");
}