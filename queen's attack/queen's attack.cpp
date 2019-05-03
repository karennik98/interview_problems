#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool is_obstacles(int row, int colum, vector<vector<int>> &obstacles) {
  for (size_t i = 0; i < obstacles.size(); i++) {
    if (obstacles[i][0] == row && obstacles[i][1]) {
      return true;
    }
  }
  return false;
}

int horizontal_count(int n, int r_q, int c_q, vector<vector<int>> &obstacles) {
  int row = r_q + 1;
  size_t count = 0;
  while (row <= n) {
    if (!is_obstacles(row, c_q, obstacles)) {
      count++;
      row++;
    } else {
      break;
    }
  }
  row = r_q - 1;
  while (row >= 1) {
    if (!is_obstacles(row, c_q, obstacles)) {
      count++;
      row--;
    } else {
      break;
    }
  }
  return count;
}

int vertical_count(int n, int r_q, int c_q, vector<vector<int>> &obstacles) {
  int colum = c_q + 1;
  size_t count = 0;
  while (colum <= n) {
    if (!is_obstacles(r_q, colum, obstacles)) {
      count++;
      colum++;
    } else {
      break;
    }
  }
  colum = c_q - 1;
  while (colum != 0) {
    if (!is_obstacles(r_q, colum, obstacles)) {
      count++;
      colum--;
    } else {
      break;
    }
  }
  return count;
}

int diagonal_count(int n, int r_q, int c_q, vector<vector<int>> &obstacles) {
  size_t count = 0;
  int row = r_q + 1;
  int colum = c_q + 1;

  while (row <= n && colum <= n) {
    if (!is_obstacles(row, colum, obstacles)) {
      count++;
      row++;
      colum++;
    } else
      break;
  }

  row = r_q - 1;
  colum = c_q - 1;
  while (row > 0 && colum > 0) {
    if (!is_obstacles(row, colum, obstacles)) {
      count++;
      row--;
      colum--;
    } else
      break;
  }

  row = r_q + 1;
  colum = c_q - 1;
  while (row <= n && colum > 0) {
    if (!is_obstacles(row, colum, obstacles)) {
      count++;
      row++;
      colum--;
    } else
      break;
  }

  row = r_q - 1;
  colum = c_q + 1;
  while (row > 0 && colum <= n) {
    if (!is_obstacles(row, colum, obstacles)) {
      count++;
      row--;
      colum++;
    } else
      break;
  }
  return count;
}

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
  return (horizontal_count(n, r_q, c_q, obstacles) +
          vertical_count(n, r_q, c_q, obstacles)   +
          diagonal_count(n, r_q, c_q, obstacles));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
