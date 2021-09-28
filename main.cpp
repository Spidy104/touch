#include <iostream>
#include <fstream>
#include <cctype>

bool exists(char *filename);

void make_file(char *filename, int exist_state);

void file_creator(int argc, char *const *argv);

constexpr int EXIST_STATE(1);

int main(int argc, char *argv[]) {
    file_creator(argc, argv);
    if (argc > 1) {
        std::cout << "Thanks for using the touch command :)\n";
    }
    return 0;

}

void file_creator(int argc, char *const *argv) {
    for (int i = 1; i < argc; ++i) {
        if (exists(argv[i])) {
            std::cout << argv[i] << " exists!!\nDo u wanna replace it(y/N)\n";
            char ch;
            std::cin >> ch;
            top :
            if (toupper(ch) == 'Y') {
                make_file(argv[i], 1);
            } else if (tolower(ch) == 'n') {
                continue;
            } else {
                std::cout << "Invalid character\nRe-enter again!\n";
                std::cin >> ch;
                goto top;
            }

        } else {
            make_file(argv[i], 0);
        }
    }
}

void make_file(char *filename, int exist_state) {
    std::fstream file;
    try {
        file.open(filename, std::ios::out);
        std::cout << (exist_state == EXIST_STATE ? "File was replaced successfully!!!\n"
                                                 : "File was created successfully!!!\n");
    } catch (std::exception &e) {
        std::cerr << "Error during file creation!!!\n";
    }
}

bool exists(char *filename) {
    struct stat buffer{};
    return stat(filename, &buffer) == 0;
}
