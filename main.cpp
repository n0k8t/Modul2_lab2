#include "TBinaryTree.h"

int main()
{
    {
        TBinaryTree tree;


        try
        {
            tree.Insert(10);
            tree.Insert(20);
            tree.Insert(1);
            tree.Insert(2);
            tree.Insert(15);

            tree.Insert(-10);
            tree.Insert(10);
        }
        catch(const TExistElementException & e)
        {
            std::cout << e.what();
        }

        std::cout << tree << std::endl << std::endl;

        
        try
        {
            TBinaryTree::TNode * found = tree.Find(2);
            if(found)
                std::cout << found->Data;
        }
        catch (const TNotFoundException & e)
        {
            std::cout << "Exception works" << std::endl;
            std::cout << e.what();
        }

                
        std::cout << std::endl;

        
        try
        {
            TBinaryTree::TNode * found_ = tree.Find(15);
            if(found_)
                std::cout << found_->Data;
        }
        catch (const TNotFoundException & e)
        {
            std::cout << "Exception works" << std::endl;
            std::cout << e.what();
        }
        
    }
}
