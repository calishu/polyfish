project('polyfish', 'cpp', version: '0.0.1-alpha')

source_files = ['src/main.cpp']

dep_wlroots = subproject('wlroots').get_variable('wlroots')

deps = [dep_wlroots]
build_args = []

target = executable(
    meson.project_name(),
    source_files,
    install : true,
    dependencies : deps,
    cpp_args : build_args,
)