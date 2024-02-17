/*
 Navicat MySQL Data Transfer

 Source Server         : localhost_3306
 Source Server Type    : MySQL
 Source Server Version : 80031
 Source Host           : localhost:3306
 Source Schema         : qing

 Target Server Type    : MySQL
 Target Server Version : 80031
 File Encoding         : 65001

 Date: 25/10/2023 21:14:59
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for sys_dict
-- ----------------------------
DROP TABLE IF EXISTS `sys_dict`;
CREATE TABLE `sys_dict`  (
  `id` int NOT NULL AUTO_INCREMENT COMMENT 'id',
  `name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '名称',
  `value` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '内容',
  `type` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '类型',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 6 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of sys_dict
-- ----------------------------
INSERT INTO `sys_dict` VALUES (1, 'user', 'el-icon-user', 'icon');
INSERT INTO `sys_dict` VALUES (2, 'house', 'el-icon-house', 'icon');
INSERT INTO `sys_dict` VALUES (3, 'menu', 'el-icon-menu', 'icon');
INSERT INTO `sys_dict` VALUES (4, 's-custom', 'el-icon-s-custom', 'icon');
INSERT INTO `sys_dict` VALUES (5, 's-grid', 'el-icon-s-grid', 'icon');
INSERT INTO `sys_dict` VALUES (6, 'document', 'el-icon-document', 'icon');

-- ----------------------------
-- Table structure for sys_file
-- ----------------------------
DROP TABLE IF EXISTS `sys_file`;
CREATE TABLE `sys_file`  (
  `id` int NOT NULL AUTO_INCREMENT COMMENT 'id',
  `name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '文件名称',
  `type` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '文件类型',
  `size` bigint NULL DEFAULT NULL COMMENT '文件大小',
  `url` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '下载链接',
  `md5` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '文件md5',
  `is_delete` tinyint(1) NULL DEFAULT 0 COMMENT '是否删除',
  `enable` tinyint(1) NULL DEFAULT 1 COMMENT '是否禁用链接',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 36 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of sys_file
-- ----------------------------
INSERT INTO `sys_file` VALUES (15, '微信图片_20230802105918.jpg', 'jpg', 55, 'http://localhost:9090/file/e140461598904eda8c3b4cbdd4cabe33.jpg', '94c79a7797048031b68f14c21afab77f', 0, 1);
INSERT INTO `sys_file` VALUES (16, '微信图片_20230802105918.jpg', 'jpg', 55, 'http://localhost:9090/file/e140461598904eda8c3b4cbdd4cabe33.jpg', '94c79a7797048031b68f14c21afab77f', 0, 1);
INSERT INTO `sys_file` VALUES (17, '配置.md', 'md', 7, 'http://localhost:9090/file/258a37c289854e13b4f7b69dafa6523b.md', '64aca715746dbf39814dab9dbdbf140d', 0, 1);
INSERT INTO `sys_file` VALUES (18, 'NEWS.txt', 'txt', 59, 'http://localhost:9090/file/cd2abf2d10864ddc9dfea949e620116b.txt', 'c97b6bb3dbc6f6770bb24d2b13795f2f', 0, 1);
INSERT INTO `sys_file` VALUES (19, '_a_：锚元素 - HTML（超文本标记语言） _ MDN -联想浏览器 2023_8_12 9_01_17.png', 'png', 5, 'http://localhost:9090/file/76dd2cf7f626461b8993b1e3176617a4.png', 'e10e0e679229a162b04f6153e8d14fd7', 1, 1);
INSERT INTO `sys_file` VALUES (20, '后台管理系统.mm', 'mm', 1, 'http://localhost:9090/file/ff427055797649b0b1915eda7e4bf581.mm', 'cc0d010855fd03867e85b5145f1806e2', 1, 1);
INSERT INTO `sys_file` VALUES (21, 'el-menu-item index=home  template slot=title    i class=el-icon-housei    span slot=title主页span.md', 'md', 1, 'http://localhost:9090/file/ed74a6b66987404dbbb44fdf05126bdc.md', 'f74d56a60ac3b0b089f9f71a2cddfa14', 1, 1);
INSERT INTO `sys_file` VALUES (22, '新建 文本文档.txt', 'txt', 0, 'http://localhost:9090/file/2afcf743e7494581a08fefaf70bfcac4.txt', 'd41d8cd98f00b204e9800998ecf8427e', 1, 1);
INSERT INTO `sys_file` VALUES (23, 'xml version=1.0 encoding=UTF-8.md', 'md', 8, 'http://localhost:9090/file/6e557371ec934db3b380c56ab1417cd8.md', 'a3a4d3b21698d961b8f004ca60aecd4c', 1, 1);
INSERT INTO `sys_file` VALUES (24, '新建 文本文档.txt', 'txt', 0, 'http://localhost:9090/file/2afcf743e7494581a08fefaf70bfcac4.txt', 'd41d8cd98f00b204e9800998ecf8427e', 1, 1);
INSERT INTO `sys_file` VALUES (25, 'HTML                                     script setup.md', 'md', 6, 'http://localhost:9090/file/acc6174db2b44bd49f3b78078c1f2999.md', 'f01769ee2b618420d6cbf1b488176802', 1, 1);
INSERT INTO `sys_file` VALUES (26, '配置.md', 'md', 7, 'http://localhost:9090/file/258a37c289854e13b4f7b69dafa6523b.md', '64aca715746dbf39814dab9dbdbf140d', 1, 1);
INSERT INTO `sys_file` VALUES (27, '数据库设计.mm', 'mm', 3, 'http://localhost:9090/file/64732e3ffd7e4e72b536156839737ed8.mm', '4b7cfe9b97746634d223aec061a55333', 1, 1);
INSERT INTO `sys_file` VALUES (28, '微信图片_20230802105918.jpg', 'jpg', 55, 'http://localhost:9090/file/e140461598904eda8c3b4cbdd4cabe33.jpg', '94c79a7797048031b68f14c21afab77f', 0, 1);
INSERT INTO `sys_file` VALUES (29, 'xml version=1.0 encoding=UTF-8.md', 'md', 8, 'http://localhost:9090/file/6e557371ec934db3b380c56ab1417cd8.md', 'a3a4d3b21698d961b8f004ca60aecd4c', 1, 0);
INSERT INTO `sys_file` VALUES (30, 'xml version=1.0 encoding=UTF-8.md', 'md', 8, 'http://localhost:9090/file/6e557371ec934db3b380c56ab1417cd8.md', 'a3a4d3b21698d961b8f004ca60aecd4c', 1, 0);
INSERT INTO `sys_file` VALUES (31, '新建 文本文档.txt', 'txt', 0, 'http://localhost:9090/file/2afcf743e7494581a08fefaf70bfcac4.txt', 'd41d8cd98f00b204e9800998ecf8427e', 1, 0);
INSERT INTO `sys_file` VALUES (32, 'el-menu-item index=home  template slot=title    i class=el-icon-housei    span slot=title主页span.md', 'md', 1, 'http://localhost:9090/file/ed74a6b66987404dbbb44fdf05126bdc.md', 'f74d56a60ac3b0b089f9f71a2cddfa14', 1, 1);
INSERT INTO `sys_file` VALUES (33, '配置.md', 'md', 7, 'http://localhost:9090/file/258a37c289854e13b4f7b69dafa6523b.md', '64aca715746dbf39814dab9dbdbf140d', 1, 0);
INSERT INTO `sys_file` VALUES (34, '后台管理系统项目介绍.md', 'md', 1, 'http://localhost:9090/file/ba772a2895d149308027cddc14159cf2.md', 'f217ee6bc87e0fb4cbae0cac408a287f', 1, 0);
INSERT INTO `sys_file` VALUES (35, 'HTML.md', 'md', 13, 'http://localhost:9090/file/203b879b75744739a9c524fd55c5e1d1.md', '67019fb75365c3748505f297847837d8', 1, 0);
INSERT INTO `sys_file` VALUES (36, '数据库设计.mm', 'mm', 3, 'http://localhost:9090/file/64732e3ffd7e4e72b536156839737ed8.mm', '4b7cfe9b97746634d223aec061a55333', 1, 1);

-- ----------------------------
-- Table structure for sys_menu
-- ----------------------------
DROP TABLE IF EXISTS `sys_menu`;
CREATE TABLE `sys_menu`  (
  `id` int NOT NULL AUTO_INCREMENT COMMENT 'id',
  `name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '名称',
  `path` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '路径',
  `icon` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '图标',
  `description` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '描述',
  `pid` int NULL DEFAULT NULL COMMENT '父级id',
  `page_path` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '页面路径',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 24 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of sys_menu
-- ----------------------------
INSERT INTO `sys_menu` VALUES (2, '系统管理', NULL, 'el-icon-s-grid', NULL, NULL, NULL);
INSERT INTO `sys_menu` VALUES (3, '用户管理', '/user', 'el-icon-user', NULL, 2, 'User');
INSERT INTO `sys_menu` VALUES (4, '角色管理', '/role', 'el-icon-s-custom', NULL, 2, 'Role');
INSERT INTO `sys_menu` VALUES (5, '菜单管理', '/menu', 'el-icon-menu', NULL, 2, 'Menu');
INSERT INTO `sys_menu` VALUES (7, '文件管理', '/file', 'el-icon-document', NULL, 2, 'File');

-- ----------------------------
-- Table structure for sys_role
-- ----------------------------
DROP TABLE IF EXISTS `sys_role`;
CREATE TABLE `sys_role`  (
  `id` int NOT NULL AUTO_INCREMENT COMMENT 'id',
  `name` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '名称',
  `description` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '描述',
  `flag` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '唯一标识',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of sys_role
-- ----------------------------
INSERT INTO `sys_role` VALUES (1, '管理员', '管理员', 'ROLE_ADMIN');
INSERT INTO `sys_role` VALUES (2, '普通用户', '普通用户', 'ROLE_USER');

-- ----------------------------
-- Table structure for sys_role_menu
-- ----------------------------
DROP TABLE IF EXISTS `sys_role_menu`;
CREATE TABLE `sys_role_menu`  (
  `role_id` int NOT NULL COMMENT '角色id',
  `menu_id` int NOT NULL COMMENT '菜单id',
  `id` int NOT NULL AUTO_INCREMENT COMMENT 'id',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 140 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci COMMENT = '角色菜单关系表' ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of sys_role_menu
-- ----------------------------
INSERT INTO `sys_role_menu` VALUES (3, 1, 104);
INSERT INTO `sys_role_menu` VALUES (3, 2, 105);
INSERT INTO `sys_role_menu` VALUES (3, 3, 106);
INSERT INTO `sys_role_menu` VALUES (3, 4, 107);
INSERT INTO `sys_role_menu` VALUES (3, 5, 108);
INSERT INTO `sys_role_menu` VALUES (3, 7, 109);
INSERT INTO `sys_role_menu` VALUES (1, 1, 128);
INSERT INTO `sys_role_menu` VALUES (1, 2, 129);
INSERT INTO `sys_role_menu` VALUES (1, 3, 130);
INSERT INTO `sys_role_menu` VALUES (1, 4, 131);
INSERT INTO `sys_role_menu` VALUES (1, 5, 132);
INSERT INTO `sys_role_menu` VALUES (1, 7, 133);
INSERT INTO `sys_role_menu` VALUES (2, 1, 138);
INSERT INTO `sys_role_menu` VALUES (2, 2, 139);
INSERT INTO `sys_role_menu` VALUES (2, 7, 140);

-- ----------------------------
-- Table structure for sys_user
-- ----------------------------
DROP TABLE IF EXISTS `sys_user`;
CREATE TABLE `sys_user`  (
  `id` int NOT NULL AUTO_INCREMENT COMMENT 'id',
  `username` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '用户名',
  `password` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '密码',
  `nickname` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '昵称',
  `email` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '邮箱',
  `phone` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '电话',
  `address` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '地址',
  `create_time` datetime(0) NULL DEFAULT CURRENT_TIMESTAMP(0) COMMENT '创建时间',
  `avtar_url` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '头像',
  `role` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL COMMENT '角色',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1614135360 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of sys_user
-- ----------------------------
INSERT INTO `sys_user` VALUES (-835338238, '007', '25d55ad283aa400af464c76d713c07ad', '77', '2378@qq.com', '18888888888', '中国', '2023-07-29 09:32:27', '微信图片_20230731110544.jpg', 'ROLE_ADMIN');
INSERT INTO `sys_user` VALUES (2, '008', 'e10adc3949ba59abbe56e057f20f883e', '44444', '2378@qq.com', '17777777777', '中国', '2023-07-28 01:38:05', '', 'ROLE_USER');
INSERT INTO `sys_user` VALUES (3, '654456', 'd41d8cd98f00b204e9800998ecf8427e', '00000', '2378@qq.com', '18666666666', '中国', '2023-07-28 02:47:12', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (5, 'fffd', 'd41d8cd98f00b204e9800998ecf8427e', '0000', '2378@qq.com', '18888888886', '中国', '2023-07-28 02:47:31', NULL, 'ROLE_ADMIN');
INSERT INTO `sys_user` VALUES (1614135301, 'wsddd', 'd41d8cd98f00b204e9800998ecf8427e', '0000', '2378@qq.com', '18888888885', '中国', '2023-07-31 21:13:10', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135303, '654654', 'd41d8cd98f00b204e9800998ecf8427e', '1000', '2378@qq.com', '18888888884', '中国', '2023-08-01 18:55:25', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135304, '987987', 'd41d8cd98f00b204e9800998ecf8427e', '1000', '2378@qq.com', '18888888883', '中国', '2023-08-01 18:55:32', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135305, '789789', 'd41d8cd98f00b204e9800998ecf8427e', '00000', '2378@qq.com', '18888888882', '中国', '2023-08-01 18:55:48', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135306, '987654', 'd41d8cd98f00b204e9800998ecf8427e', '4400', '2378@qq.com', '18888888881', '中国', '2023-08-01 21:30:46', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135307, '6352441', NULL, '1000', '2378@qq.com', '18888888879', '中国', '2023-08-02 16:13:15', NULL, 'ROLE_ADMIN');
INSERT INTO `sys_user` VALUES (1614135311, '12345', 'adcaec3805aa912c0d0b14a81bedb6ff', '12345', '2378@qq.com', '18888888878', '中国', '2023-08-14 14:24:59', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135312, '110110', '70873e8580c9900986939611618d7b1e', '7000', '2378@qq.com', '18888888877', '中国', '2023-08-14 14:44:22', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135315, 'User', NULL, 'User00', '2378@qq.com', '18888888876', '中国', '2023-08-15 08:36:44', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135328, '123456', 'e10adc3949ba59abbe56e057f20f883e', '123456', '2378@qq.com', '18888888875', '中国', '2023-08-15 15:39:58', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135329, '1234567', 'e10adc3949ba59abbe56e057f20f883e', '1234567', '2378@qq.com', '18888888748', '中国', '2023-08-15 15:42:50', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135335, '321123', '123456', '123456', '2378@qq.com', '18888888873', '中国', '2023-08-15 16:52:32', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135336, '789456', 'e10adc3949ba59abbe56e057f20f883e', '0000', '2378@qq.com', '18888888872', '中国', '2023-08-15 19:55:29', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135337, '123123', '123123', '000', '2378@qq.com', '18888888871', '中国', '2023-08-15 20:37:46', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135338, 'asdf', 'd41d8cd98f00b204e9800998ecf8427e', '000', '2378@qq.com', '18888888870', '中国', '2023-08-15 21:07:41', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135339, 'sadf', '46f227e9cf17e2e1e88b14e679047bd9', '000', '2378@qq.com', '18888888868', '中国', '2023-08-15 21:08:36', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135340, 'fdsdf', 'd68c0a364200c6cff81ddd750f37ba21', '000', '2378@qq.com', '18888888867', '中国', '2023-08-15 21:17:12', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135341, 'asdfasdf', 'f6e14f67668392a47638c756c43b8e1d', '000', '2378@qq.com', '18888888866', '中国', '2023-08-15 21:18:03', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135342, 'fdf', '202cb962ac59075b964b07152d234b70', '000', '2378@qq.com', '18888888825', '中国', '2023-08-15 22:03:19', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135346, '123', 'd41d8cd98f00b204e9800998ecf8427e', NULL, '2675309054@qq.com', '18888888868', NULL, '2023-08-16 10:23:48', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135348, 'asdf', '350c9d901b7f1c73a481e240ec1b7c0b', NULL, '1115271969@qq.com', '15536983507', '1212', '2023-08-16 14:58:12', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135357, '456456', '74be16979710d4c4e7c6647856088456', NULL, '1115271969@qq.com', '15536983507', '1212', '2023-08-16 16:03:18', NULL, 'ROLE_USER');
INSERT INTO `sys_user` VALUES (1614135358, '14438', 'd41d8cd98f00b204e9800998ecf8427e', NULL, '1115271969@qq.com', '15536983507', '1212', '2023-08-16 16:09:38', NULL, 'ROLE_USER');

SET FOREIGN_KEY_CHECKS = 1;
