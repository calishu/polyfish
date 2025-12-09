project('polyfish', 'c', version: '0.0.1-alpha')

source_files = ['src/main.c']

dep_wlroots = subproject('wlroots').get_variable('wlroots')

deps = [dep_wlroots]
build_args = ['-DWLR_USE_UNSTABLE']

add_project_arguments(
    '-DWLR_USE_UNSTABLE',
    language: 'c',
)

target = executable(
    meson.project_name(),
    source_files,
    install : true,
    dependencies : deps,
)