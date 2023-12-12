#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

void createMatrixFromFile (const std::string& numberss , int columns, int& sumDiagonal) {
    std::ifstream file("/Users/senyaghtbs/CLionProjects/LABA4SEM2/numberss.txt");
    if (!file) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return;
    }

    std::vector<int> numbers;
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }

    int rows = numbers.size() / columns;
    int extraElements = numbers.size() % columns;

    std::cout << "Матрица:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int index = i * columns + j;
            std::cout << numbers[index] << " ";
            if (i + j == columns - 1) {
                sumDiagonal += numbers[index];
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Размерность матрицы: " << rows << "x" << columns << std::endl;
    std::cout << "Сумма элементов побочной диагонали: " << sumDiagonal << std::endl;

    if (extraElements > 0) {
        std::cout << "Внимание: отброшены лишние элементы (" << extraElements << ")." << std::endl;
    }

    file.close();
}

void createMatrixWithFiveElementsPerRowFromFile(const std::string& numberss , int& sumPreLastRow) {
    std::ifstream file("/Users/senyaghtbs/CLionProjects/LABA4SEM2/numberss.txt");
    if (!file) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return;
    }

    std::vector<int> numbers;
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }

    int rows = numbers.size() / 5;
    int extraElements = numbers.size() % 5;

    std::cout << "Матрица:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 5; ++j) {
            int index = i * 5 + j;
            std::cout << numbers[index] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Размерность матрицы: " << rows << "x5" << std::endl;

    if (extraElements > 0) {
        std::cout << "Внимание: отброшены лишние элементы (" << extraElements << ")." << std::endl;
    }

    if (rows >= 2) {
        sumPreLastRow = 0;
        for (int j = 0; j < 5; ++j) {
            int index = (rows - 2) * 5 + j;
            sumPreLastRow += numbers[index];
        }
        std::cout << "Сумма элементов предпоследней строки: " << sumPreLastRow << std::endl;
    } else {
        std::cout << "Недостаточно строк для подсчета суммы предпоследней строки." << std::endl;
    }

    file.close();
}

void mergeWordsFromFile(const std::string& slova1, const std::string& slova2) {
    std::ifstream file1("/Users/senyaghtbs/CLionProjects/LABA4SEM2/slova1.txt");
    if (!file1) {
        std::cout << "Ошибка открытия файла " << "slova1" << std::endl;
        return;
    }

    std::ifstream file2("/Users/senyaghtbs/CLionProjects/LABA4SEM2/slova2.txt");
    if (!file2) {
        std::cout << "Ошибка открытия файла " << "slova2" << std::endl;
        return;
    }

    std::vector<std::string> words1;
    std::string word;
    while (file1 >> word) {
        words1.push_back(word);
    }

    std::vector<std::string> words2;
    while (file2 >> word) {
        words2.push_back(word);
    }

    file1.close();
    file2.close();

    std::ofstream outputFile("merged_words.txt");
    if (!outputFile) {
        std::cout << "Ошибка открытия файла для записи." << std::endl;
        return;
    }

    size_t size = std::max(words1.size(), words2.size());
    for (size_t i = 0; i < size; ++i) {
        if (i < words1.size()) {
            outputFile << words1[i] << " ";
        }
        if (i < words2.size()) {
            outputFile << words2[i] << " ";
        }
    }

    outputFile.close();

    std::ifstream mergedFileRead("merged_words.txt");
    std::string line;

    if (mergedFileRead) {
        std::cout << "Содержимое файла merged_words.txt:" << std::endl;
        while (std::getline(mergedFileRead, line)) {
            std::cout << line << std::endl;
        }
        mergedFileRead.close();
    } else {
        std::cout << "Ошибка при открытии файла merged_words.txt." << std::endl;
    }
}


void findAndSortWords(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::vector<std::vector<std::string>> wordsByLength(20);

    std::string word;
    while (inputFile >> word) {
        if (word.length() < wordsByLength.size()) {
            wordsByLength[word.length()].push_back(word);
        }
    }

    inputFile.close();

    bool foundWords = false;
    for (size_t i = 0; i < wordsByLength.size(); i++) {
        if (wordsByLength[i].size() > 1) {
            std::cout << "слова с" << i << " буквами:" << std::endl;
            for (const auto& word : wordsByLength[i]) {
                std::cout << word << std::endl;
            }
            foundWords = true;
        }
    }

    if (!foundWords) {
        std::cout << "слова с такой длинной не найдены." << std::endl;
    }
}
void createSquareMatrixWithLast16NumbersFromFile(const std::string& numberss, int& sumAboveDiagonal) {
    std::ifstream file("/Users/senyaghtbs/CLionProjects/LABA4SEM2/numberss.txt");
    if (!file) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return;
    }

    std::vector<int> numbers;
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }

    int size = std::min(16, static_cast<int>(numbers.size()));
    int sqrtSize = sqrt(size);
    int extraElements = numbers.size() - size;

    std::cout << "Квадратная матрица:" << std::endl;
    for (int i = 0; i < sqrtSize; ++i) {
        for (int j = 0; j < sqrtSize; ++j) {
            int index = (size - sqrtSize) + i * sqrtSize + j;
            std::cout << numbers[index] << " ";
            if (i < j) {
                sumAboveDiagonal += numbers[index];
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Размерность матрицы: " << sqrtSize << "x" << sqrtSize << std::endl;
    std::cout << "Сумма элементов над главной диагональю: " << sumAboveDiagonal << std::endl;

    if (extraElements > 0) {
        std::cout << "Внимание: отброшены лишние элементы (" << extraElements << ")." << std::endl;
    }

    file.close();
}

void SymmetricWords(const std::string& filename) {
        std::ifstream inputFile("/Users/senyaghtbs/CLionProjects/LABA4SEM2/slova2.txt");
        if (!inputFile.is_open()) {
            std::cout << "Невозможно открыть файл: " << filename << std::endl;
            return;
        }

        std::vector<std::string> words;

        std::string word;
        while (inputFile >> word) {
            words.push_back(word);
        }

        std::vector<std::string> sameLengthWords;
        for (size_t i = 0; i < words.size(); i++) {
            for (size_t j = i + 1; j < words.size(); j++) {
                if (words[i].length() == words[j].length()) {
                    sameLengthWords.push_back(words[i]);
                    sameLengthWords.push_back(words[j]);
                }
            }
        }

        if (sameLengthWords.empty()) {
            std::cout << "Слова с одинаковой длиной не найдены:(" << std::endl;
        } else {
            std::cout << "Слова с одинаковой длиной:" << std::endl;
            for (const auto& word : sameLengthWords) {
                std::cout << word << std::endl;
            }
        }

        inputFile.close();
    }
void createNewFileWithDigits(const std::string& numberss2, const std::string& newFilename) {
    std::ifstream file("/Users/senyaghtbs/CLionProjects/LABA4SEM2/numberss2.txt");
    if (!file) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return;
    }

    std::vector<int> digits;
    int digit;
    while (file >> digit) {
        digits.push_back(digit);
    }

    file.close();

    std::sort(digits.begin(), digits.end(), [](int a, int b) {
        return std::to_string(a).size() > std::to_string(b).size();
    });

    std::ofstream newFile(newFilename);
    if (!newFile) {
        std::cout << "Ошибка открытия файла для записи." << std::endl;
        return;
    }

    std::cout << "Новый файл создан." << std::endl;

    for (int d : digits) {
        newFile << d << std::endl;
    }

    newFile.close();

    int minDigit = digits.back();
    int maxDigit = digits.front();

    std::cout << "Минимальное число: " << minDigit << std::endl;
    std::cout << "Максимальное число: " << maxDigit << std::endl;
}

void selectAndPrintSentences(const std::string& predlojenie) {
    std::ifstream file("/Users/senyaghtbs/CLionProjects/LABA4SEM2/predlojenie.txt");
    if (!file) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return;
    }

    std::vector<std::string> sentences;
    std::string sentence;
    while (std::getline(file, sentence, '.')) {
        sentences.push_back(sentence);
    }

    file.close();

    if (sentences.size() >= 4) {
        std::string secondSentence = sentences[1];
        std::string fourthSentence = sentences[3];

        int secondSentenceLength = secondSentence.size();
        int fourthSentenceLength = fourthSentence.size();

        std::cout << "Второе предложение: " << secondSentence << std::endl;
        std::cout << "Число букв во втором предложении: " << secondSentenceLength << std::endl;

        std::cout << "Четвертое предложение: " << fourthSentence << std::endl;
        std::cout << "Число букв в четвертом предложении: " << fourthSentenceLength << std::endl;

        std::cout << "Меньшее из двух предложений по длине: ";
        if (secondSentenceLength <= fourthSentenceLength) {
            std::cout << secondSentenceLength << std::endl;
        } else {
            std::cout << fourthSentenceLength << std::endl;
        }
    } else {
        std::cout << "Недостаточно предложений в файле." << std::endl;
    }
}

void replaceCharactersInTextFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cout << "Невозможно открыть файл: " << filename << std::endl;
        return;
    }

    std::string line;
    std::string sentence1, sentence2, sentence3;

    // Чтение предложений из файла
    size_t sentenceCount = 0;
    while (std::getline(inputFile, line)) {
        if (!line.empty()) {
            if (sentenceCount == 0) {
                sentence1 = line;
            } else if (sentenceCount == 1) {
                sentence2 = line;
            } else if (sentenceCount == 2) {
                sentence3 = line;
                break; // Прекращаем чтение после третьего предложения
            }
            sentenceCount++;
        }
    }

    inputFile.close();

    // Замена символов в предложениях
    size_t index = sentence1.find(L'и');
    while (index != std::string::npos) {
        sentence1[index] = L'е';
        index = sentence1.find(L'и', index + 1);
    }

    index = sentence2.find(L'а');
    while (index != std::string::npos) {
        sentence2[index] = L'о';
        index = sentence2.find(L'а', index + 1);
    }

    // Запись измененных предложений в файл
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cout << "Невозможно открыть файл для записи: " << filename << std::endl;
        return;
    }

    outputFile << sentence1 << std::endl;
    outputFile << sentence2 << std::endl;
    outputFile << sentence3 << std::endl;

    outputFile.close();

    std::cout << "Замена символов выполнена успешно." << std::endl;

    // Вывод измененных предложений
    std::cout << "Измененные предложения:" << std::endl;
    std::cout << "1. " << sentence1 << std::endl;
    std::cout << "2. " << sentence2 << std::endl;
    std::cout << "3. " << sentence3 << std::endl;
}



int countWordsStartingWithLetter(const std::string& filename, char letter) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return 0;
    }

    int count = 0;
    std::string word;
    while (file >> word) {
        if (!word.empty() && (word[0] == letter || std::tolower(word[0]) == std::tolower(letter))) {
            ++count;
        }
    }

    file.close();

    return count;
}



void printMenu() {
    std::cout << "Меню:" << std::endl;
    std::cout << "1. Задача 1: Формирование матрицы из чисел в файле" << std::endl;
    std::cout << "2. Задача 2: Формирование матрицы из чисел с пятью элементами в строке" << std::endl;
    std::cout << "3. Задача 3: Слияние двух файлов с чередованием слов" << std::endl;
    std::cout << "4. Задача 4: Выборка слов из файла, состоящих из семи букв (в алфавитном порядке)" << std::endl;
    std::cout << "5. Задача 5: Формирование квадратной матрицы из последних 16 чисел в файле" << std::endl;
    std::cout << "6. Задача 6: Поиск симметричных слов в файле" << std::endl;
    std::cout << "7. Задача 7: Формирование нового файла с отсортированными числами" << std::endl;
    std::cout << "8. Задача 8: Выборка предложений из файла" << std::endl;
    std::cout << "9. Задача 9: Замена символов в текстовом файле" << std::endl;
    std::cout << "10. Задача 10: Подсчет количества слов, начинающихся с определенной буквы" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Введите номер задачи: ";
}

int main() {
    int choice;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string filename;
                int columns, sumDiagonal = 0;
                std::cout << "Введите количество столбцов: ";
                std::cin >> columns;
                createMatrixFromFile("numberss.txt", columns, sumDiagonal);
                break;
            }
            case 2: {
                std::string filename;
                int sumPreLastRow = 0;
                createMatrixWithFiveElementsPerRowFromFile("numberss.txt", sumPreLastRow);
                break;
            }
            case 3: {
                std::string filename1, filename2;
                mergeWordsFromFile(filename1, filename2);
                break;
            }
            case 4: {
                std::string filename = "/Users/senyaghtbs/CLionProjects/LABA4SEM2/slova1.txt";
                findAndSortWords(filename);
                break;
            }
            case 5: {
                std::string filename;
                int sumAboveDiagonal = 0;
                createSquareMatrixWithLast16NumbersFromFile("numberss.txt", sumAboveDiagonal);
                break;
            }
            case 6: {
                std::string filename;
                SymmetricWords(filename);
                break;
            }
            case 7: {
                std::string filename, newFilename;
                std::cin >> newFilename;
                createNewFileWithDigits("numberss2.txt", newFilename);
                break;
            }
            case 8: {
                std::string filename;
                selectAndPrintSentences("predlojenie.txt");
                break;
            }
            case 9: {
                std::string filename = "/Users/senyaghtbs/CLionProjects/LABA4SEM2/predlojenie.txt";
                replaceCharactersInTextFile(filename);
                break;
            }

            case 10: {
                std::string filename = "/Users/senyaghtbs/CLionProjects/LABA4SEM2/predlojenie2.txt";
                char letter;

                std::cout << "Введите букву для поиска: ";
                std::cin >> letter;

                int wordCount = countWordsStartingWithLetter(filename, letter);

                std::cout << "Количество слов, начинающихся с буквы '" << letter << "': " << wordCount << std::endl;

                break;
            }


            case 0:
                std::cout << "Программа завершена." << std::endl;
                break;
            default:
                std::cout << "Неверный ввод. Повторите попытку." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (choice != 0);

    return 0;
}