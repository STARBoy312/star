import sys
import cv2
from PyQt5.QtWidgets import (
    QApplication, QWidget, QPushButton, QLabel, QVBoxLayout,
    QHBoxLayout, QFileDialog, QMessageBox, QTextEdit
)
from PyQt5.QtGui import QPixmap, QImage
from PyQt5.QtCore import Qt
from ultralytics import YOLO  # 引入 YOLOv8 模型

# 主窗口类
class YoloApp(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("YOLOv8 图像/视频检测")  # 设置窗口标题
        self.setGeometry(200, 200, 1000, 600)  # 设置窗口大小和位置

        # 加载已经训练好的 YOLOv8 模型
        self.model = YOLO("best.pt")

        # 用于显示图像的标签
        self.image_label = QLabel("请选择图片或视频")
        self.image_label.setAlignment(Qt.AlignCenter)
        self.image_label.setFixedSize(640, 480)

        # 用于显示检测信息的文本框
        self.result_info = QTextEdit()
        self.result_info.setReadOnly(True)  # 只读
        self.result_info.setFixedSize(320, 480)

        # 两个按钮：选择图片 和 选择视频
        self.btn_image = QPushButton("选择图片")
        self.btn_video = QPushButton("选择视频")

        # 绑定按钮点击事件
        self.btn_image.clicked.connect(self.load_image)
        self.btn_video.clicked.connect(self.load_video)

        # 左侧图像 + 右侧文本框 的水平布局
        content_layout = QHBoxLayout()
        content_layout.addWidget(self.image_label)
        content_layout.addWidget(self.result_info)

        # 整体垂直布局：上图像信息，下两个按钮
        main_layout = QVBoxLayout()
        main_layout.addLayout(content_layout)
        main_layout.addWidget(self.btn_image)
        main_layout.addWidget(self.btn_video)

        self.setLayout(main_layout)

    # 加载图片并检测
    def load_image(self):
        # 打开文件选择对话框
        file_path, _ = QFileDialog.getOpenFileName(self, "选择图片", "", "Images (*.png *.jpg *.jpeg)")
        if file_path:
            # 使用 YOLOv8 模型进行推理，source 为图片路径
            results = self.model.predict(source=file_path, save=False, show=False)
            # 获取结果图像（带框）
            img = results[0].plot()

            # 显示检测后的图像
            self.display_image(img)
            # 保存输出图像（可选）
            cv2.imwrite("output_image.jpg", img)
            # 显示检测信息
            self.show_detection_info(results[0])

    # 加载视频并检测
    def load_video(self):
        file_path, _ = QFileDialog.getOpenFileName(self, "选择视频", "", "Videos (*.mp4 *.avi *.mov)")
        if file_path:
            save_path = "runs/detect/pyqt_video"
            # 运行视频检测，保存输出视频到指定目录
            self.model.predict(source=file_path, save=True, show=False, project="runs/detect", name="pyqt_video")
            # 提示检测完成
            QMessageBox.information(self, "检测完成", f"视频检测已完成，保存在：{save_path}")
            self.result_info.setText("视频检测完成，已保存至:\n" + save_path)

    # 在界面中显示图片
    def display_image(self, cv_img):
        # 将 BGR 转换为 RGB（Qt 显示用）
        rgb_img = cv2.cvtColor(cv_img, cv2.COLOR_BGR2RGB)
        h, w, ch = rgb_img.shape
        bytes_per_line = ch * w
        # 将 numpy 图像转为 QImage
        q_img = QImage(rgb_img.data, w, h, bytes_per_line, QImage.Format_RGB888)
        # 缩放图像并显示在标签上
        pixmap = QPixmap.fromImage(q_img).scaled(self.image_label.size(), Qt.KeepAspectRatio)
        self.image_label.setPixmap(pixmap)

    # 显示检测框信息（类别、置信度、坐标）
    def show_detection_info(self, result):
        info = ""
        boxes = result.boxes  # 检测框信息
        names = result.names  # 类别名映射

        num = len(boxes)  # 检测到的目标数量
        info += f"检测到对象数：{num}\n\n"

        for i, box in enumerate(boxes):
            cls_id = int(box.cls[0])  # 类别 ID
            class_name = names[cls_id] if cls_id in names else f"ID {cls_id}"  # 类别名
            conf = float(box.conf[0])  # 置信度
            x1, y1, x2, y2 = map(int, box.xyxy[0])  # 框的左上角和右下角坐标
            w = x2 - x1
            h = y2 - y1

            info += (
                f"对象 {i+1}:\n"
                f"  类别：{class_name}\n"
                f"  置信度：{conf:.2f}\n"
                f"  位置：({x1}, {y1}) - ({x2}, {y2})\n"
                f"  宽高：{w}x{h}\n\n"
            )

        self.result_info.setText(info)


# 主程序入口
if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = YoloApp()
    window.show()
    sys.exit(app.exec_())  # 启动事件循环
