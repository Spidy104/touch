#include <iostream>
#include <fstream>

bool exists(char *filename);

void make_file(char *filename);

void file_creator(int argc, char *const *argv);

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
                std::fstream file;
                try {
                    file.open(argv[i], std::ios::out);
                    std::cout << "File was replaced successfully!!!\n";
                } catch (std::exception &e) {
                    std::cerr << "Error during file creation!!!\n";
                }
            } else if (tolower(ch) == 'n') {
                continue;
            } else {
                std::cout << "Invalid character\nRe-enter again!\n";
                std::cin >> ch;
                goto top;
            }

        } else {
            make_file(argv[i]);
        }
    }
}

void make_file(char *filename) {
    std::fstream file;
    try {
        file.open(filename, std::ios::out);
        std::cout << "File was created successfully!!!\n";
    } catch (std::exception &e) {
        std::cerr << "Error during file creation!!!\n";
    }
}

bool exists(char *filename) {
    struct stat buffer{};
    return (stat(filename, &buffer) == 0);
}
