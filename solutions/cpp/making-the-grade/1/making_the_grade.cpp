#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
  std::vector<int> int_vec;

  for (auto score : student_scores) {
    int_vec.push_back(static_cast<int>(score));
  }
  return int_vec;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
  int failed_students{0};

  for (auto score : student_scores) {
    if (score <= 40) {
      failed_students++;
    }
  }
  return failed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {

  std::array<int, 4> letter_grades;
  int interval{(highest_score - 40) / 4};

  for (int i{0}; i < letter_grades.size(); i++) {
    letter_grades[i] = 41 + (interval * i);
  }
  return letter_grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string>
student_ranking(std::vector<int> student_scores,
                std::vector<std::string> student_names) {

  std::vector<std::string> student_ranking;

  for (int i{0}; i < student_scores.size(); i++) {

    std::string student_info = std::to_string(i + 1) + ". " + student_names[i] +
                               ": " + std::to_string(student_scores[i]);

    student_ranking.push_back(student_info);
  }
  return student_ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {

  std::string perfect_student{""};

  for (int i{0}; i < student_scores.size(); i++) {
    if (student_scores[i] == 100) {
      perfect_student = student_names[i];
      break;
    }
  }
  return perfect_student;
}
