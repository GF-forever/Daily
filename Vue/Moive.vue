<template>
  <div class="film">
    <div class="filmLeft">
      <h3>屏幕</h3>
      <ul>
        <li v-for="(item, index) in seatflag" :key="index" class="seat"
            :class="{'noSeat' : seatflag[index]==-1,
            'seatSpace' : seatflag[index]==0,
            'seatActive' : seatflag[index]==1,
            'seatNoUse' : seatflag[index]==2}"
            @click="handleClick(index)">
        </li>
      </ul>
    </div>
    <div class="filmRight">
      <div class="rightTop">
        <div class="rightTopleft">
          <a href="#">
            <img :src="filmInfo.filmImg" alt="..." height="200">
          </a>
        </div>
        <div class="rightTopRight">
          <p >中文名：<strong>{{filmInfo.name}}</strong></p>
          <p >英文名：{{filmInfo.nameEnglish}}</p>
          <p>剧情：{{filmInfo.storyType}}</p>
          <p>版本：{{filmInfo.copyRight}}</p>
          <p>{{filmInfo.place}} / {{filmInfo.timeLength}}</p>
          <p>{{filmInfo.timeShow}}</p>
        </div>
      </div>
      <div class="rightBootom">
         <p>影院：<strong>{{filmInfo.cinema}}</strong></p>
          <p>影厅：<strong>{{filmInfo.room}}</strong></p>
          <p>简介：<strong>{{filmInfo.intro}}</strong></p>
          <p id="seatSelect">
            座位：
            <span v-for="(item, index) in curSeatDisp" :key="index">
              {{item}}
            </span>
          </p>
          <p>已选择<strong style="color:red;">{{count}}</strong>个座位<br>
            <strong style="color:red;">
              再次单击座位可取消。
          <span v-if="maxFlag">您一次最多只能买五张票！</span></strong></p>
          <hr>
          <p>单价：<strong>{{numberFormat(filmInfo.unitPrice)}}</strong></p>
          <p>总价：<strong style="color:red;">{{numberFormat(filmTotal)}}</strong></p>
          <hr>
          <button type="button" class="btn" @click="filmSubmit">
            确认下单
          </button>
      </div>
    </div>
  </div>
</template>
<script>
import { reactive, toRefs, computed} from 'vue'
import FilmImg from './assets/244.jpg'
export default {
    setup () {
        const st = reactive({
            curSeat: [],
            curSeatDisp: [],
            count: 0,
            maxFlag: false,
            maxLenght: 5,
            seatCol: 10,
            seatflag: [
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 2, 0, 0, 2, 0, 0, 0,
                -1, 0, 0, 0, 0, 0, 0, 0, 0, -1,
                0, -1, 0, 0, 0, 0, 0, 0, -1, 0
            ],
            filmInfo: {
                name: '画江湖之天罡传',
                nameEnglish: 'The Legend',
                copyRight: '普通话',
                filmImg: FilmImg,
                storyType: '动画、动作',
                place: '内地',
                timeLength:'1:41:00',
                timeshow: '2023-12-29',
                cinema: '腾讯视频',
                room: '云包场',
                intro: '大周年间，时局动荡，奸臣当道。直属帝王的秘密暗杀组织不良人一夜之间突然群龙无首不良帅袁天罡留下一纸书信辞官而去。失去人生方向的袁天罡，在好友李淳风留下的锦囊的指引下，来到了长安安乐阁，却不曾想到此地竟是风月之所。而接下来发生的一切，随着寻求自由之人、寻求不死之人、寻求权力之人的逐一登场，为袁天罡的旅途拉开了新的序幕...',
                unitPrice: 18
            }
        })
        const handleClick = (index) => {
            if (st.seatflag[index] === 1) {
                st.seatflag[index] = 0
                st.curSeat.splice(st.curSeat.findIndex(item => item === index), 1)
            }else{
                if (st.seatflag[index] === 0 && st.curSeat.length < 5) {
                    st.seatflag[index] = 1
                    st.curSeat.push(index)
                }
            }
            st.curSeatDisp = []
            for (const data of st.curSeat) {
                st.curSeatDisp.push((Math.floor(data / st.seatCol) + 1) + '行' + (data % st.seatCol + 1) + '列')
            }
            var nm = st.seatflag.filter(item => item === 1)
            st.count = nm.length
            if (st.count >= 5) st.maxFlag = true
            else st.maxFlag = false
        }
        const filmTotal = computed(() =>
            st.count*st.filmInfo.unitPrice
        )
        const numberFormat = (value) => '￥' + value.toFixed(2)
        return {
            ...toRefs(st),
            filmTotal,
            handleClick,
            numberFormat
        }
    }
}
</script>
<style scoped>
  .film{
    margin: 0 auto;
    width: 1100px;
    border:1px solid grey;
    height: 650px;

  }
  .filmLeft{
    width:550px;
    height: 500px;
    float: left;
  }
  .filmLeft h3{
    text-align: center;
  }
  .filmLeft ul {
    list-style: none;
  }
  .filmRight{
    width:500px;
    height: 560px;
    float: left;
    background-color: rgba(45, 194, 202, 0.774);
  }
.rightTopleft{
  float: left;
  margin: 20px 15px 5px 10px;
}
.rightTopRight{
  float: left;
  margin:0px 0px 5px 5px
}
.rightBootom{
  clear: both;
  margin: 0px 10px;
}
.rightBootom p{
  line-height: 25px;
}
.rightTopRight p{
  line-height: 36px;
}
.seat {
    float: left;
    width: 30px;
    height: 30px;
    background-color: bisque;
    margin: 5px 10px;
    cursor: pointer;
  }
  .seatNotice {
    float: left;
    width: 30px;
    height: 30px;
    margin: 5px 10px;
    background-color: bisque;
    list-style: none;
    margin-left: 50px;
  }

  .notice {
    float: left;
    height: 30px;
    line-height: 30px;
  }

        .seatSpace {
            background: url('./assets/bg.png') no-repeat 1px -29px;
        }

        .seatActive {
            background: url('./assets/bg.png') 1px 0px;
        }

        .seatNoUse {
            background: url('./assets/bg.png') 1px -56px;
        }

        .noSeat {
            background: url('./assets/bg.png') 1px -84px;
        }
#filmInformation,#filmRightTopLeft{
  float: left;
 }
#filmRightBottom{
  clear: both;
}

        #filmInformation h4,
        #filmInformation p {
            font-size: 20px;
            margin-left: 15px;
            margin-bottom: 14px;
        }

        #filmInformation p {
            font-size: 16px;
            margin-left: 15px;
        }

        .sceenRight {
            background-color: bisque;
            height: 650px;
            padding-top: 10px;
        }

        .sceenRight>p {
            color: red;
            font-size: 28px;

        }

        .filmCurrent {
            font-size: 16px;
            margin: 5px;
        }

        .filmCurrent p {
            margin: 15px;
        }

        #seatSelect span {
            padding: 5px;
            border: 1px solid red;
            margin: 8px;
            font-size: 14px;
            background-color: white;
            font-weight: bold;
            color: red;
        }
        .btn{
          margin: 15px 150px;
          width: 120px;
          height: 40px;
          background-color: rgb(68, 168, 135);
          color: white;
          cursor: pointer;
        }
</style>
