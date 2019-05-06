# 构建环境配置

- 将 `include` 下的头文件拷贝到`Qt安装目录\Qt\Qt5.9.0\Tools\QtCreator\bin\plugins\designer\include`中(`include`文件夹需手动创建)。

- 将`lib`下的`customwidgetplugin.dll`拷贝到`Qt安装目录\Qt\Qt5.9.0\Tools\QtCreator\bin\plugins\designer`下。

- 将`lib`下的`customwidgetplugin.lib`拷贝到`Qt安装目录\Qt\Qt5.9.0\Tools\QtCreator\bin\plugins\designer\lib`下(`lib`文件夹需要手动创建)。

- `customwidgetplugin.dll`&`customwidgetplugin.lib`使用`msvc 2015 32` 位编译器构建，并且为`release`版。
- 本工程也需要`msvc 2015 32`位  `release` 版。