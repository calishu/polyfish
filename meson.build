project('polyfish', 'cpp', version: '0.0.1-alpha')

source_files = ['src/main.cpp']
include_dir  = include_directories('include')

dep_wlroots = subproject('wlroots').get_variable('wlroots')

deps = [dep_wlroots]

add_project_arguments(
    '-DWLR_USE_UNSTABLE',
    language: 'cpp',
)

target = executable(
    meson.project_name(),
    source_files,
    install : true,
    dependencies : deps,
    include_directories : include_dir,
)