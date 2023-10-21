project('ventilation-c', 'cpp', version : '0.1.0', default_options : ['warning_level=3', 'cpp_std=c++20'])

includes      = include_directories('include')
sources       = [
    'source/ventilation.cpp'

  , 'source/ventilation-compliance.cpp'
  , 'source/ventilation-elastance.cpp'
  , 'source/ventilation-resistance.cpp'
  
  , 'source/ventilation-flow.cpp'
  , 'source/ventilation-pressure.cpp'
  , 'source/ventilation-volume.cpp'
  , 'source/ventilation-packet.cpp'

  , 'source/ventilation-lung.cpp'
  ]
dependencies  = [dependency('ventilation')]

ventilation       = library(
  'ventilation'
  , sources
  , include_directories : includes
  , dependencies        : dependencies
  , install             : true
  )

ventilation_c_dep = declare_dependency(
  link_with             : ventilation
  , include_directories : includes
  , dependencies        : dependencies
  )

if not meson.is_subproject()
  subdir('example')
  subdir('tests')
endif
