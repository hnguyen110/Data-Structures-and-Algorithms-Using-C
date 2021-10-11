#include "gtest.h"
#include "hashmap.h"

struct HashmapTest : testing::Test {
    Hashmap<int> *_hashmap;

    HashmapTest() {
        _hashmap = new Hashmap<int>(10);
    }

    ~HashmapTest() override {
        delete _hashmap;
    }
};

TEST_F(HashmapTest, TESTING_HASHMAP) {
    EXPECT_EQ(_hashmap->Size(), 0);
    EXPECT_EQ(_hashmap->Get("some_key"), nullptr);
    _hashmap->Add("one", new int (1));
    _hashmap->Add("two", new int (2));
    _hashmap->Add("three", new int (3));
    _hashmap->Add("four", new int (4));
    _hashmap->Add("five", new int (5));
    EXPECT_EQ(*_hashmap->Get("one"), 1);
    EXPECT_EQ(*_hashmap->Get("two"), 2);
    EXPECT_EQ(*_hashmap->Get("three"), 3);
    EXPECT_EQ(*_hashmap->Get("four"), 4);
    EXPECT_EQ(*_hashmap->Get("five"), 5);
    EXPECT_EQ(_hashmap->Size(), 5);
    _hashmap->Remove("one");
    EXPECT_EQ(_hashmap->Get("one"), nullptr);
    EXPECT_EQ(*_hashmap->Get("two"), 2);
    EXPECT_EQ(*_hashmap->Get("three"), 3);
    EXPECT_EQ(*_hashmap->Get("four"), 4);
    EXPECT_EQ(*_hashmap->Get("five"), 5);
    EXPECT_EQ(_hashmap->Size(), 4);
    _hashmap->Remove("one");
    _hashmap->Remove("two");
    EXPECT_EQ(_hashmap->Get("one"), nullptr);
    EXPECT_EQ(_hashmap->Get("two"), nullptr);
    EXPECT_EQ(_hashmap->Size(), 3);
    _hashmap->Clear();
    EXPECT_EQ(_hashmap->Get("one"), nullptr);
    EXPECT_EQ(_hashmap->Get("two"), nullptr);
    EXPECT_EQ(_hashmap->Get("three"), nullptr);
    EXPECT_EQ(_hashmap->Get("four"), nullptr);
    EXPECT_EQ(_hashmap->Get("five"), nullptr);
    EXPECT_EQ(_hashmap->Size(), 0);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
