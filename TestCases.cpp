#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.cpp"

class MockFileReader : public FileReader {
public:
    MOCK_METHOD(std::vector<Student>, readFile, (const std::string&), (override));
};

class MockFileParser : public FileParser {
public:
    MOCK_METHOD(CourseInfo, parseFile, (const std::string&), (override));
};

class MockHeaderMaker : public HeaderMaker {
public:
    MOCK_METHOD(std::string, makeHeader, (const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&), (override));
};

class MockFileWriter : public FileWriter {
public:
    MOCK_METHOD(void, writeToFile, (const std::vector<Student>&, const std::string&, const std::string&), (override));
};

TEST(MainFunctionality, SuccessfulDataProcessing) {
    MockFileReader mockFileReader;
    MockFileParser mockFileParser;
    MockHeaderMaker mockHeaderMaker;
    MockFileWriter mockFileWriter;

    std::vector<Student> students = { Student(1, "John Doe", "JD123", "Registered", "Senior", "15", "A", "A", "A") };
    FileParser::CourseInfo courseInfo = { "CS101", "12345", "Spring 2022" };

    EXPECT_CALL(mockFileReader, readFile).Times(1).WillOnce(testing::Return(students));
    EXPECT_CALL(mockFileParser, parseFile).Times(1).WillOnce(testing::Return(courseInfo));
    EXPECT_CALL(mockHeaderMaker, makeHeader).Times(1).WillOnce(testing::Return("HEADER"));
    EXPECT_CALL(mockFileWriter, writeToFile).Times(1);

    // Call the main function
    main();
}

TEST(MainFunctionality, FileOpeningFailure) {
    MockFileReader mockFileReader;

    EXPECT_CALL(mockFileReader, readFile).Times(0);

    // Call the main function with a non-existing file
    main();
}

TEST(MainFunctionality, EmptyFilePath) {
    std::string filePath = filePathVerifier("");
    ASSERT_EQ(filePath, "./Resources/Data/ejemploDatos.txt");
}

TEST(MainFunctionality, FilePathWithoutExtension) {
    std::string filePath = filePathVerifier("testFile");
    ASSERT_EQ(filePath, "./Resources/Data/testFile.txt");
}

TEST(MainFunctionality, FilePathWithQuotes) {
    std::string filePath = filePathVerifier("\"testFile.txt\"");
    ASSERT_EQ(filePath, "./Resources/Data/testFile.txt");
}

TEST(MainFunctionality, OutputFilePathWithoutExtension) {
    std::string filePath = outputFilePathVerifier("testFile");
    ASSERT_EQ(filePath, "./Resources/Output/testFile.csv");
}

TEST(MainFunctionality, OutputFilePathWithQuotes) {
    std::string filePath = outputFilePathVerifier("\"testFile.csv\"");
    ASSERT_EQ(filePath, "./Resources/Output/testFile.csv");
}