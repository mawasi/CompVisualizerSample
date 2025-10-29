# CompVisualizerSample
UE5のComponentVisualizerSampleプロジェクト

## Description

UnrealEngine Version 5.6.1

ComponentVisualizerの実装サンプルプロジェクト  
別プロジェクトへコピペで実装できるように最低限必要なものをまとめた  


## memo

Vector系メンバーをシーンビュー上で操作するためにマニピュレータを実装する場合、  
ComponentVisualizerが参照するコンポーネントがSceneComponent継承じゃないとうまくマニピュレータが表示されない  

パラメータをシーンビュー上に視覚化するだけならActorComponent継承コンポーネントでも問題ない  



## Reference

[Extending Unreal Editor with Component Visualizer ](https://dev.epicgames.com/community/learning/tutorials/KP5p/unreal-engine-extending-unreal-editor-with-component-visualizer?utm_source=chatgpt.com)  
[【UE5】ComponentVisualizerを活用してデータを視覚化](https://shuntaendo.hatenablog.com/entry/2023/12/1/000000)  
