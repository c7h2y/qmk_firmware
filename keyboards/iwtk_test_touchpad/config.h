// I2C1 のピンを GP10(GP11) に割り当て
#define I2C1_SDA_PIN GP10
#define I2C1_SCL_PIN GP11

// 使うコントローラは I2C1
#define I2C_DRIVER   I2CD1

// （任意）バス速度
#define F_SCL        400000  // 100kでもOK

/* ==== Azoteq TPS43 を使う宣言 ==== */
#define AZOTEQ_IQS5XX_TPS43 1   // 解像度プリセット等に使用

/* ==== スクロールの初期しきい値（任意、好みで調整） ==== */
#define AZOTEQ_IQS5XX_SCROLL_INITIAL_DISTANCE 10  // 初期値50→10にすると反応が軽快

