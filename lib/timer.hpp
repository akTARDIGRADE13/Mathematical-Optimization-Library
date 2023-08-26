#include <chrono>

namespace akTARDIGRADE13 {
struct Timer {
private:
  std::chrono::system_clock::time_point start_time_;
  double time_threshold_;

  double now_time_ = 0;

public:
  // 時間制限をミリ秒単位で指定してインスタンスをつくる
  Timer(const double time_threshold)
      : start_time_(std::chrono::system_clock::now()),
        time_threshold_(time_threshold) {}

  // 経過時間をnow_time_に格納する
  void setNowTime() {
    auto diff = std::chrono::system_clock::now() - this->start_time_;
    this->now_time_ = (std::chrono::duration_cast<std::chrono::microseconds>(diff).count() * 1e-3);
  }

  // 経過時間をnow_time_に取得する
  double getNowTime() const { return this->now_time_; }

  // インスタンス生成した時から指定した時間制限を超過したか判定する
  bool isTimeOver() const { return now_time_ >= time_threshold_; }
};
} // namespace akTARDIGRADE13