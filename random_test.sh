#!/bin/bash

# ------ パラメータ ------ 
# ファイル
GENERATOR='./gens/bin/number.out'
NAIVE='./sample/number_sum/naive.out'
SMART='./sample/number_sum/smart_wa.out'
# テスト回数
LOOP_COUNT=10
# WAが何回出たら停止するか
STOP_THREASHOLD=2
# ファイル出力オプション 1：ALL 2：WAのみ
OUTPUT_OPTION=2
# テスト方法 1：1ファイル 2：2ファイル
TEST_OPTION=2
# ------------------------ 

# フォルダ・ファイル準備
RESULT_FOLDER='result_'$(date '+%Y%m%d%H%M%S')
mkdir ${RESULT_FOLDER}
touch ${RESULT_FOLDER}/fails

start_time=$(date +%s.%3N)
wa_count=0

for i in $(seq -f '%04g' 1 ${LOOP_COUNT}); do
    # 入力生成
    eval ${GENERATOR} > ${RESULT_FOLDER}/${i}_input

    # テスト対象実行
    eval ${SMART} < ${RESULT_FOLDER}/${i}_input > ${RESULT_FOLDER}/${i}_output 2>> ${RESULT_FOLDER}/errors

    # 結果判定（okなら0、ngなら0以外）
    # テストオプション1の場合は終了コードで判定する
    result=${?}
    # テストオプション2の場合は愚直コードとの等価性判定
    if [[ ${TEST_OPTION} = 2 ]]; then
        # 愚直コードとの等価性比較
        eval ${NAIVE} < ${RESULT_FOLDER}/${i}_input > ${RESULT_FOLDER}/${i}_expected
        result=$(diff --brief ${RESULT_FOLDER}/${i}_expected ${RESULT_FOLDER}/${i}_output)
        if [[ -n ${result} ]]; then
            result=1
        else
            result=0
        fi
    fi

    # 結果に応じた処理
    if [[ ${result} != 0 ]]; then
        echo ${i} >> ${RESULT_FOLDER}/fails
        # WAの個数が閾値を越えたら終了する
        ((wa_count++))
        if [[ ${wa_count} == ${STOP_THREASHOLD} ]]; then
            LOOP_COUNT=${i}
            break
        fi
    # ACの入出力を保存しないオプションの場合
    elif [[ ${OUTPUT_OPTION} = 2 ]]; then
        rm -f ${RESULT_FOLDER}/${i}_*
    fi
done

# ランダムテスト結果出力
result=$(cat ${RESULT_FOLDER}/fails)
if [[ -n ${result} ]]; then
    echo '[Wrong Answer]    '${result}
else
    echo 'OK'
fi

# 経過時間
end_time=$(date +%s.%3N)
tot_time=$(echo "scale=4; ${end_time} - ${start_time}" | bc)
ave_time=$(echo "scale=4; ${tot_time} / ${LOOP_COUNT}" | bc)
echo '[elapsed time]    total: '${tot_time}'    avelavge: '${ave_time}