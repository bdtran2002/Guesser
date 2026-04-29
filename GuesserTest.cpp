/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"
#include <string>
using namespace std;

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
//TEST(GuesserTest, smoke_test){
//  Guesser object("Secret");
//  ASSERT_EQ( 1+1, 2 );
//}

TEST(GuesserTest, distance_identical){
  Guesser object("Secret");
  unsigned int actual = object.distance("Secret");
  ASSERT_EQ(0, actual);
}

TEST(GuesserTest, distance_identical_all_upper){
  Guesser object("SECRET");
  unsigned int actual = object.distance("SECRET");
  ASSERT_EQ(0, actual);
}

TEST(GuesserTest, distance_identical_all_lower){
  Guesser object("secret");
  unsigned int actual = object.distance("secret");
  ASSERT_EQ(0, actual);
}

TEST(GuesserTest, distance_one_char_diff){
  Guesser object("Secret");
  unsigned int actual = object.distance("SecreT");
  ASSERT_EQ(1, actual);
}

TEST(GuesserTest, distance_all_diff){
  Guesser object("Secret");
  unsigned int actual = object.distance("xxxxxx");
  ASSERT_EQ(6, actual);
}

TEST(GuesserTest, distance_guess_longer){
  Guesser object("Secret");
  unsigned int actual = object.distance("Secret123");
  ASSERT_EQ(3, actual);
}

TEST(GuesserTest, truncated_secret){
  Guesser object("12345678901234567890123456789012!");
  unsigned int actual = object.distance("12345678901234567890123456789012");
  ASSERT_EQ(0, actual);
}

TEST(GuesserTest, distance_guess_shorter){
  Guesser object("Secret");
  unsigned int actual = object.distance("Sec");
  ASSERT_EQ(3, actual);
}	

TEST(GuesserTest, match_test){
  Guesser object("Secret");
   bool actual = object.match("Secret");
  ASSERT_EQ(true, actual);
}		

TEST(GuesserTest, match_wrong_guess){
  Guesser object("Secret");
 bool actual = object.match("SecreT");
  ASSERT_EQ(false, actual);
}

TEST(GuesserTest, match_wrong_guess_2){
  Guesser object("Secret");
bool actual = object.match("xxxxxx");
  ASSERT_EQ(false, actual);
}	

TEST(GuesserTest, match_wrong_guess_3){
  Guesser object("Secret");
 bool actual = object.match("Secre");
bool actual2 = object.match("Secr");
 bool actual3 = object.match("Sec");
  ASSERT_EQ(false, actual3);
}	

TEST(GuesserTest, match_brute_force_lock){
  Guesser object("Secret");
bool actual = object.match("xxxxdlajfa;sldkffjals;djfalkdjf;alkdjf;adlkfjas;dja;lkre;aldjs;lkvajd;lkfja;sldkfja;lsdkjf;alskdjf;alksdjncaskdlj;faxx");
bool actual2 = object.match("Secret");
  ASSERT_EQ(false, actual2);
}		

TEST(GuesserTest, match_lock_after_3_wrong_guesses){
  Guesser object("Secret");
bool actual = object.match("Secre");
bool actual2 = object.match("Secr");
 bool actual3 = object.match("Sec");
bool actual4 = object.match("Secret");
  ASSERT_EQ(false, actual4);
}





