#include "Utility.hpp"


namespace Utility {
    // generate random vector based on seed
    float* generate_problem(int seed, int dim, int num_points){
        std::mt19937 random(seed);
        std::uniform_real_distribution<float> distribution(-100, 100);
        float* x = (float*)calloc(dim * num_points, sizeof(float));

        for(int n = 0; n < num_points; ++n){
            for(int d = 0; d < dim; ++d){
                *(x + n * dim + d) = distribution(random);
            }
        }

        return x;
    }

    // print head and left-most / right-most leafs of node
    void print_head_and_leaves(Node* tree){
        Node* head = tree;
        Node* left_leaf = head;
        Node* right_leaf = head;
        
        while(left_leaf->left != nullptr){
            left_leaf = left_leaf->left;
        }
        while(right_leaf->right != nullptr){
            right_leaf = right_leaf->right;
        }

        std::cout << std::endl << "Head: " << *head->point << std::endl;
        std::cout << "Left Leaf: " << *left_leaf->point << std::endl;
        std::cout << "Right Leaf: " << *right_leaf->point << std::endl << std::endl;
    }


    // free tree which is built dynamially
    void free_tree(Node* root){
        if (root == nullptr){return;}
        free_tree(root->left);
        free_tree(root->right);
        delete root;
    }


    // helper function to print tree
    void print_tree_rec(Node* root, int depth){
        if (root == nullptr){return;}
        for(int d = 0; d < depth; ++d){
            std::cout << "\t";
        }
        std::cout << "NODE(@depth=" << depth << "): " << *root->point << std::endl;
        print_tree_rec(root->left, depth + 1);
        print_tree_rec(root->right, depth + 1);
    }


    // helper function to print tree
    void print_tree(Node* root){
        print_tree_rec(root, 0);
    }


    void validate_input(int seed, int dim, int num_points){
        if (seed == 0) {
            std::cerr << "Warning: default value 0 used as seed." << std::endl;
        }

        if(seed < 0){
            std::cerr << "Seed has to be larger than 0!" << std::endl;
            exit(1);
        }

        if (dim <= 0) {
            std::cerr << "Dimension has to be larger than 0!" << std::endl;
            exit(1);
        }

        if (num_points <= 0) {
            std::cerr << "Number of points has to be larger than 0!" << std::endl;
            exit(1);
        }

        std::cerr << "\tUsing seed " << seed << std::endl;
        std::cerr << "\tUsing point dimensions " << dim << std::endl; 
        std::cerr << "\tUsing number of points " << num_points << std::endl << std::endl;
    }


    void specify_problem(int* seed, int* dim, int* num_points){
        std::cout << "READY" << std::endl;
        
        std::cerr << "Specify seed ";
        std::cin >> *seed;
        
        *dim = 128;
        *num_points = 500000;

        validate_input(*seed, *dim, *num_points);
    }
        
    void specify_problem(int argc, char** argv, int* seed, int* dim, int* num_points){
        // validate arguments
        // you will receive a string specifying the dataset you work on and
        // a initialization number determining the initialization used in
        // training the network to get the correct weights
        if (argc != 4) {
            std::cerr << "Usage: " << argv[0] << " SEED DIM_POINTS  NUM_POINTS" << std::endl;
            exit(1);
        }
        
        std::cout << "READY" << std::endl;
        *seed = std::stoi(argv[1]);
        *dim = std::stoi(argv[2]);
        *num_points = std::stoi(argv[3]);

        validate_input(*seed, *dim, *num_points);
    }

    void print_result_line(int ID, float distance){
        std::cout << "ID: " << ID << " \t DISTANCE: " << distance << std::endl;
    }
}