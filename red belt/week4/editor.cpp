#include <string>
#include <list>
#include <deque>
#include <iterator>
#include "test_runner.h"
#include "profile.h"
using namespace std;
class Editor {
public:
    // Реализуйте конструктор по умолчанию и объявленные методы
    Editor() {
        coursorPosition_ = text_.begin();
    }
    void Left();
    void Right();
    void Insert(char token);
    void Cut(size_t tokens = 1);
    void Copy(size_t tokens = 1);
    void Paste();
    const size_t GetTextSize() const {
        return text_.size();
    }
    string GetText() const;
private:
    list<char> text_;
    list<char> buffer_;
    list<char>::iterator coursorPosition_;
};

void Editor::Left() {
    if (coursorPosition_ != text_.begin()) {
        --coursorPosition_;
    }
}

void Editor::Right() {
    if (coursorPosition_ != text_.end()) {
        ++coursorPosition_;
    }
}

void Editor::Insert(char token) {
    text_.insert(coursorPosition_, token);
}

void Editor::Cut(size_t tokens) {
    Copy(tokens);
    size_t size = min(tokens, static_cast<size_t>(distance(coursorPosition_, text_.end())));

    coursorPosition_ = text_.erase(coursorPosition_, next(coursorPosition_, size));
}

void Editor::Copy(size_t tokens) {
    buffer_.clear();
    size_t size = min(tokens, static_cast<size_t>(distance(coursorPosition_, text_.end())));
    auto it_begin = coursorPosition_;
    auto it_end = next(it_begin, size);
    while(it_begin != it_end) {
        buffer_.push_back(*it_begin);
        ++it_begin;
    }
}

void Editor::Paste() {
    auto it_begin = buffer_.begin();
    while(it_begin != end(buffer_)) {
        Insert(*it_begin);
        ++it_begin;
    }
}

string Editor::GetText() const {
    string result;
    result.resize(text_.size());
    auto it = text_.begin();
    for (size_t i = 0; i < text_.size(); ++i) {
        result[i] = *it;
        ++it;
    }
    return result;
}

void TypeText(Editor& editor, const string& text) {
    for(char c : text) {
        editor.Insert(c);
    }
}

void TestEditing() {
    {
        Editor editor;

        const size_t text_len = 12;
        const size_t first_part_len = 7;
        TypeText(editor, "hello, world");
        for(size_t i = 0; i < text_len; ++i) {
            editor.Left();
        }
        editor.Cut(first_part_len);
        for(size_t i = 0; i < text_len - first_part_len; ++i) {
            editor.Right();
        }
        TypeText(editor, ", ");
        editor.Paste();
        editor.Left();
        editor.Left();
        editor.Cut(3);

        ASSERT_EQUAL(editor.GetText(), "world, hello");
    }
    {
        Editor editor;

        TypeText(editor, "misprnit");
        editor.Left();
        editor.Left();
        editor.Left();
        editor.Cut(1);
        editor.Right();
        editor.Paste();

        ASSERT_EQUAL(editor.GetText(), "misprint");
    }
}

void TestReverse() {
    Editor editor;

    const string text = "esreveR";
    for(char c : text) {
        editor.Insert(c);
        editor.Left();
    }

    ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
    Editor editor;
    ASSERT_EQUAL(editor.GetText(), "");

    editor.Left();
    editor.Left();
    editor.Right();
    editor.Right();
    editor.Copy(0);
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
    Editor editor;

    editor.Paste();
    TypeText(editor, "example");
    editor.Left();
    editor.Left();
    editor.Paste();
    editor.Right();
    editor.Paste();
    editor.Copy(0);
    editor.Paste();
    editor.Left();
    editor.Cut(0);
    editor.Paste();

    ASSERT_EQUAL(editor.GetText(), "example");
}

void TestInsertMax() {
    Editor editor;
    for (size_t i = 0; i < 1000000; i++) {
        editor.Insert('a');
    }
}

void CreateFullEditor(Editor& editor) {
    for (size_t i = 0; i < 1000000; i++) {
        editor.Insert('a');
    }
}

void TestLeftMax(Editor& editor) {
    for (size_t i = 0; i < 1'000'000; i++) {
        editor.Left();
    }
}

void TestRightMax(Editor& editor) {
    for (size_t i = 0; i < 1'000'000; i++) {
        editor.Right();
    }
}

void TestCopyMax(Editor& editor) {
    for (size_t i = 0; i < 1'000'000; i++) {
        editor.Copy(editor.GetTextSize());
    }
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestEditing);
    RUN_TEST(tr, TestReverse);
    RUN_TEST(tr, TestNoText);
    RUN_TEST(tr, TestEmptyBuffer);
    {
        LOG_DURATION("10^6 Insert()")
        TestInsertMax();
    }
    Editor editor;
    CreateFullEditor(editor);
    {
        LOG_DURATION("10^6 Left()")
        TestLeftMax(editor);
    }
    {
        LOG_DURATION("10^6 Right()")
        TestRightMax(editor);
    }
    {
        LOG_DURATION("10^6 Copy()")
        TestCopyMax(editor);
    }
    return 0;
}