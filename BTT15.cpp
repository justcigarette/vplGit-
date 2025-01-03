#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BookNode {
public:
    string title;              
    int page_count;             
    int level;                 
    vector<BookNode*> children; 

   
    BookNode(string title, int page_count, int level)
        : title(title), page_count(page_count), level(level) {}

    
    void add_child(BookNode* child) {
        children.push_back(child);
    }

    
    void print_node() const {
        cout << title << " (" << page_count << " pages)" << endl;
    }
};

// a 
int count_chapters(BookNode* root) {
    if (!root) return 0;
    int chapter_count = (root->level == 1) ? 1 : 0; 
    for (BookNode* child : root->children) {
        chapter_count += count_chapters(child); 
    }
    return chapter_count;
}

// b
BookNode* find_longest_chapter(BookNode* root) {
    BookNode* longest_chapter = nullptr;
    int max_pages = 0;

    if (root) {
        if (root->level == 1 && root->page_count > max_pages) {
            longest_chapter = root;
            max_pages = root->page_count;
        }
        for (BookNode* child : root->children) {
            BookNode* longest_in_child = find_longest_chapter(child);
            if (longest_in_child && longest_in_child->page_count > max_pages) {
                longest_chapter = longest_in_child;
                max_pages = longest_in_child->page_count;
            }
        }
    }
    return longest_chapter;
}

// c
BookNode* delete_node(BookNode* root, const string& title_to_delete) {
    if (!root) return nullptr;

    if (root->title == title_to_delete) {
        return nullptr;
    }
n
    vector<BookNode*> new_children;
    for (BookNode* child : root->children) {
        BookNode* new_child = delete_node(child, title_to_delete);
        if (new_child) {
            new_children.push_back(new_child);
        }
    }

    root->children = new_children;
    return root;
}




